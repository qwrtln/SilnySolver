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

# Boolean semaphores for decision making
CAN_DELIVER=false
RUN_CHECK=false
POSSIBLE_SQUASH=true
MEMORY_CHECK=true

# Firstly, check if proper number of arguments was given: repo and branch
if [ "$#" -ne 2 ]
    then echo -e "Illegal number of parameters. When doing a delivery, you have to type both the name of the repository and the branch you're delivering to. For instance:\n\ngit deliver origin development\n"
# Secondly, check if the name of repo is correct
elif [ ! "$1" = "origin" ]
then
    echo -e "${RED}$1${NORMAL} doesn't appear to be a repository. Try again."
# Lastly, make sure the branch exists
else
    # Checking current branch
    BRANCH=$(git status | grep "On branch " | sed {s/"On branch "//})
    RUN_CHECK=true

    # Check if the branch that's being pushed to exists
    if ! git branch -r | grep -qo $2
    then
        echo -e "Branch ${CYAN}$2${NORMAL} doesn't seem to exist on the remote repository. In order to push, it has to be created. Continue? [y/n]"
        read createBranch 
        case "$createBranch" in
            y|Y ) echo "Very well."
                  POSSIBLE_SQUASH=false
                  ;;
            n|N ) echo "Alright, must have been a typo. Try again then."
                  RUN_CHECK=false
                  ;;
              * ) echo "Invalid input. Skipping delivery."
                  RUN_CHECK=false 
                  ;;
        esac
    fi
fi

if [ "$RUN_CHECK" = true ]
then
    echo -e  "Pushing from ${GREEN}local${NC} $BRANCH to ${RED}remote${NC} $2. Running delivery check...\n"
    
    if [ "$POSSIBLE_SQUASH" = true ]
    then
# Check if developer's trying to push more than one commit
        (( N= $(git log $1/$2..$2| grep -c 'commit [0-9a-f]\{40\}') ))
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
    fi
# Old build.log will only disturb with current check. It should be removed. 
    rm -rf *.log

# Put current build files in separate folder - move them back later
    mkdir -p .temp .temp/Dev .temp/Test
    mv Dev/build/*.o Dev/build/*.d SilnySolver .temp/Dev/ 2>/dev/null
    mv Test/build/*.o Test/build/*.d SilneTesty .temp/Test/ 2>/dev/null

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
                MEMORY_CHECK=false
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
                                  MEMORY_CHECK=false
                                  ;;
                              * ) echo "Invalid input. Aborting push." 
                                  MEMORY_CHECK=false
                                  ;;
                        esac
                        
                    fi
            fi
    else
        rm -rf build.log .buildErr.log 2>/dev/null # in this case those files are no longer needed
        echo -e "\nThe code is ${CYAN}pristine${NC}!"
        CAN_DELIVER=true
    fi

    if [ "$MEMORY_CHECK" = true ]
    then
        echo -e "\nThis is where Valgrind comes in.\n"

    fi

    # Clean up after delivery check build
        make clean > /dev/null
    # Put previous build files back where they belong 
        mv .temp/Dev/* Dev/build/ 2>/dev/null
        mv .temp/Test/* Test/build/ 2>/dev/null
        rm -rf .temp 2>/dev/null
fi

if [ "$CAN_DELIVER" = true ]
then
    git push $REPO $BRANCH
fi
