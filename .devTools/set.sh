#!/bin/bash
# The purpose of this script is to set up Git hooks, which facilitate
# the development process.

# Just to add some life
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
NORMAL=$(tput sgr0)

# Common variables
GERRIT_HOST=megacinol.duckdns.org
MAIN_URL="$(git config --get remote.origin.url)"
GERRIT_USERNAME="$(echo $MAIN_URL | cut -c 7- | sed {s/@.*//})"

mainHooks=($(ls .devTools/hooks/))
subHooks=($(ls .devTools/submodule/hooks/))
reviewers=($(cat .devTools/reviewers))

echo -n "Updating hooks..."
if rsync -rq .devTools/hooks .git/ && rsync -rq .devTools/submodule/hooks .git/modules/SilnySolverUI
then
    echo -e "\t${GREEN}OK${NORMAL}"
else
    echo -e "${YELLOW}not ok${NORMAL}"
fi

echo -n "Checking gerrit host..."
# Update ~/.ssh/config to enable access to gerrit
if grep --quiet $GERRIT_HOST ~/.ssh/config &> /dev/null
then
    echo -e "\t${GREEN}OK${NORMAL}"
else
    cat .devTools/ssh_config | sed {s/GERRIT_USERNAME/$GERRIT_USERNAME/} >> ~/.ssh/config
    echo -e "${YELLOW}updated!${NORMAL}"
fi

echo -n "Checking submodule URL.."
# Update submodule origin URL
cd SilnySolverUI
GENERIC_URL="$(git config --get remote.origin.url)"
if [ ! ${GENERIC_URL::-2} == $MAIN_URL ] # The first url ends with "UI" - we want to cut that
then
    SUBMODULE_URL="$(echo $GENERIC_URL | sed {s.\/\/gerrit.\/\/$GERRIT_USERNAME@gerrit.})"
    git remote set-url origin $SUBMODULE_URL
    echo -e "${YELLOW}updated!${NORMAL}"
else
    echo -e "${GREEN}OK${NORMAL}"
fi
cd ..

echo -n "Setting review alias..."
# Add everyone to code review when delivering to development
PUSH_URL=@:refs/for/development%r=piotoor@gmail.com # The architec is hardcoded!
for i in "${reviewers[@]}"
do
    PUSH_URL+=,r=$i
done
if git config remote.development.url $MAIN_URL && git config remote.development.push $PUSH_URL
then
    echo -e "\t${GREEN}OK${NORMAL}"
else
    echo -e "\t${YELLOW}not ok${NORMAL}"
fi

git config alias.set '!bash .devTools/set.sh'    # Set some aliases
git config alias.last 'log -1 HEAD'
git config alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"
git config alias.lgd "log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold cyan)%aD%C(reset) %C(bold green)(%ar)%C(reset)%C(bold yellow)%d%C(reset)%n''          %C(white)%s%C(reset) %C(dim white)- %an%C(reset)' --all"
git config alias.aliases "!git config --get-regexp 'alias.*' | colrm 1 6 | sed 's/[ ]/ = /' "

