#!/bin/bash
# The purpose of this script is to set up Git hooks, which facilitate
# the development process.

git config --global --unset alias.deliver # Legacy alias - deprecated
mv .git/hooks/*\.sample .git/hooks/defaults/ -f # Backup in case default hooks are needed
cp .devTools/pre-push .git/hooks/ # Set delivery check script
