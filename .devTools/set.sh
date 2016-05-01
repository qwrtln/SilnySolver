#!/bin/bash
# The purpose of this script is to set up Git hooks, which facilitate
# the development process.

git config --global --unset alias.deliver # Legacy alias - deprecated
cp .devTools/pre-push .git/hooks/ # Set delivery check script

git config alias.set '!bash .devTools/set.sh'
