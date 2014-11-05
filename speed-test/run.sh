#!/bin/bash

BLACK="\033[30m"
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
MAGENTA="\033[0;35m"
CYAN="\033[0;36m"
WHITE="\033[2;37m"
DEFAULT="\033[39m"
LIGHT_BLACK="\033[1;30m"
LIGHT_RED="\033[1;31m"
LIGHT_GREEN="\033[1;32m"
LIGHT_YELLOW="\033[1;33m"
LIGHT_BLUE="\033[1;34m"
LIGHT_MAGENTA="\033[1;35m"
LIGHT_CYAN="\033[1;36m"
LIGHT_WHITE="\033[1;37m"
NO_COLOUR="\033[0m"
BLACK_BG="\033[40m"
BLINK="\033[05m"
NORMAL="\033[00m"

echo -e "${YELLOW}Running sample 2D gradient calculations...${NORMAL}"

echo -e "\n${BLUE}Using pure C:${NORMAL}"
(cd c-del2 && make 2>&1 > /dev/null && ./program)

echo -e "\n${BLUE}Using Python's C API:${NORMAL}"
(cd c-api-del2 && make 2>&1 > /dev/null && python program.py)

echo -e "\n${BLUE}Using NumPy's f2py interface with C:${NORMAL}"
(cd c-f2py-del2 && make 2>&1 > /dev/null && python program.py)

echo -e "\n${BLUE}Using NumPy's f2py interface with fortran:${NORMAL}"
(cd f95-del2 && make 2>&1 > /dev/null && python program.py)

echo -e "\n${BLUE}Using pure Python (CPython):${NORMAL}"
(cd python-del2 && python program.py)

echo -e "\n${BLUE}Using pure Python (PyPy):${NORMAL}"
(cd python-del2 && pypy program.py)
