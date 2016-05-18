#!/bin/bash
# The purpose of this script is to set up Git hooks, which facilitate
# the development process.

hooks=(commit-msg  post-checkout  prepare-commit-msg  pre-push add-change-id)

UPDATED=true

for i in "${hooks[@]}"  # Iterate over hooks to see if they are up-to-date
do
    if ! diff ".devTools/hooks/$i" ".git/hooks/$i" >/dev/null
    then
        UPDATED=false
    fi
done

if [ "$UPDATED" = true ]
then
    echo -e "Hooks are already up to date."
else
    cp -r .devTools/hooks .git/                  # Copy all the scripts
    echo -e "Successfully copied the hooks."
fi

git config alias.set '!bash .devTools/set.sh'    # Set some aliases
git config alias.last 'log -1 HEAD'
git config alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"
git config alias.lgd "log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold cyan)%aD%C(reset) %C(bold green)(%ar)%C(reset)%C(bold yellow)%d%C(reset)%n''          %C(white)%s%C(reset) %C(dim white)- %an%C(reset)' --all"
git config alias.aliases "!git config --get-regexp 'alias.*' | colrm 1 6 | sed 's/[ ]/ = /' "
