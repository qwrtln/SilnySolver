#!/bin/bash

REPO="$1"
BRANCH="$2"

# Some variables to enhance output readability
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
CYAN='\033[1;36m'
NC='\033[0m' # No Color
BOLD=$(tput bold)
NORMAL=$(tput sgr0)

CAN_DELIVER=false
RUN_CHECK=false

# First condition to check - if you're on origin/development branch
if git status | grep -q 'On branch development'
then
    echo "You are now on the development branch."
    RUN_CHECK=true
fi

# Second condition - pushing to origin/development from anywhere
if [ "$REPO" == "origin" ] && [ "$BRANCH" == "development" ]
then
    echo "You are now pushing to development branch."
    RUN_CHECK=true
fi

if [ "$RUN_CHECK" = true ]
then
    echo -e "Running delivery check...\n"

    # Check if developer's trying to push more than one commit
    (( N= $(git log origin/feature/deliveryCheckScript..feature/deliveryCheckScript| grep -c 'commit [0-9a-f]\{40\}') ))
    if [ $N -gt 1 ]
    then    
        echo -e "You are trying to push ${YELLOW}$N commits${NC}. Would you like to ${GREEN}rebase${NC} them instead? [y/n] " 
        read rebase 
        case "$rebase" in
            y|Y ) git stash >/dev/null # Safety check. Rebasing with unstaged changes is impossible.
                  git rebase -i @~$N
                  git stash apply >/dev/null
                  ;;
            n|N ) echo -e "As you wish. Note that pushing ${RED}more than one${NC} commit makes it harder to revert your change. "
                  ;;
            * ) echo "Invalid input. Skipping rebase." 
                ;;
        esac
    fi

    # Old build.log will only disturb with current check. It should be removed. 
    rm -rf *.log
    
    # Put current build files in separate folder - move them back later
    mkdir -p .temp .temp/Dev .temp/Test
    mv Dev/build/*.o Dev/build/*.d SilnySolver .temp/Dev/
    mv Test/build/*.o Test/build/*.d SilneTesty .temp/Test/
    
    # Let's gather some build logs
    make test 2> build.log  

    if [ -s build.log ]
    then

        # Check for errors
        grep -i error build.log > .buildErr.log

            if [ -s .buildErr.log ]
            then
                echo -e "\n" 
                grep --color -i error build.log
                rm -rf .buildErr.log # remove in case of aborting
                echo -e "\nDelivery check finished with ${RED}compilation errors${NC} listed above. See build.log file for details. Please ${BOLD}correct them${NORMAL} before you continue."
                else 
                    # Check for warnings only if there are no errors
                    grep -i warning build.log > .buildWar.log
                    if [ -s .buildWar.log ]
                    then 
                        echo -e "\n" 
                        grep --color -i warning build.log
                        rm -rf .buildWar.log # remove in case of aborting
                        echo -e "\nDelivery check finished with ${YELLOW}WARNINGS${NC} listed above. See build.log file for details."
                        read -p "Are you sure you want to continue pushing? [y/n] " choice
                        case "$choice" in
                            y|Y ) echo "Forcing push..."
                                  CAN_DELIVER=true;;
                            n|N ) echo "Aborting push." 
                                  ;;
                            * ) echo "Invalid input. Aborting push." 
                                ;;
                        esac
                        
                    fi
            fi
    else
        rm -rf build.log .buildErr.log # in this case those files are no longer needed
        echo -e "\nThe code is ${CYAN}pristine${NC}!"
        CAN_DELIVER=true
    fi

    # Clean up after delivery check build
    make clean > /dev/null
    # Put previous build files back where they belong 
    mv .temp/Dev/* Dev/build/
    mv .temp/Test/* Test/build/
    rm -rf .temp

else
    echo "Not on development branch. Doing regular push."
    CAN_DELIVER=true
fi

if [ "$CAN_DELIVER" = true ]
then
    git push $REPO $BRANCH
fi

