#!/bin/bash

REPO="$1"
BRANCH="$2"

# Some variables to enhance output readability
RED='\033[1;31m'
YELLOW='\033[1;33m'
CYAN='\033[1;36m'
NC='\033[0m' # No Color
BOLD=$(tput bold)
NORMAL=$(tput sgr0)

CAN_DELIVER=false
CLEAN=false;

# Skip delivery check, if you're on a different branch than 'development'
if git status | grep -q 'On branch development'
then
    echo "You are now pushing to the development branch."
    echo -e "Running delivery check...\n"

# Old build.log will only disturb with current check. It should be removed. 
    if [ -s Dev/build/build.log ]
    then
        rm Dev/build/build.log
    fi


    pushd Dev/build > /dev/null 
    make SilnySolver 2> build.log  
    popd > /dev/null

    if [ -s Dev/build/build.log ]
    then

        # Check for errors
        grep -i error Dev/build/build.log > Dev/build/.buildErr.log

            if [ -s Dev/build/.buildErr.log ]
            then
                echo -e "\n" 
                grep --color -i error Dev/build/build.log
                echo -e "\nDelivery check finished with ${RED}compilation errors${NC} listed above. See Dev/build/build.log for details. Please ${BOLD}correct them${NORMAL} before you continue."
                else 
                    # Check for warnings only if there are no errors
                    grep -i warning Dev/build/build.log > Dev/build/.buildWar.log
                    if [ -s Dev/build/.buildWar.log ]
                    then 
                        echo -e "\n" 
                        grep --color -i warning Dev/build/build.log
                        echo -e "\nDelivery check finished with ${YELLOW}WARNINGS${NC} listed above. See Dev/build/build.log file for details."
                        read -p "Are you sure you want to continue pushing? [y/n] " choice
                        case "$choice" in
                            y|Y ) echo "Forcing push..."
                                  CAN_DELIVER=true;;
                            n|N ) echo "Skipping push." 
                                  CLEAN=true;;
                            * ) echo "Invalid input. Skipping push." 
                                CLEAN=true;;
                        esac
                        
                    fi
            fi
        # Remove temporary log files    
        rm Dev/build/\.*.log
    else
        echo -e "\nThe code is ${CYAN}pristine${NC}!"
        CAN_DELIVER=true
    fi
else
    echo "Not on development branch. Doing regular push."
    CAN_DELIVER=true
fi

# After an aborted push due to warnings, project should be cleaned
# Otherwise, after second attempt, delivery check would show pristine condition
if [ "$CLEAN" = true ]
then
    pushd Dev/build > /dev/null 
    make clean > /dev/null 
    popd > /dev/null
fi

if [ "$CAN_DELIVER" = true ]
then
    git push $REPO $BRANCH
fi

