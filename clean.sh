#!/usr/bin/env bash

BLUE='\033[1;34m'
RESET='\033[0m'

# remove all .elf files
echo -e "${BLUE}Removing binaries ...${RESET}"
rm -vrf *.exe 2> /dev/null