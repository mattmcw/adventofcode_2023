#!/bin/bash

source ../common.sh

set -e

WHICH="01"

if [[ "${2}" != "" ]]; then
	WHICH="02"
fi

g++ -std=c++11 -o ${WHICH} ${WHICH}.cpp

ANSWER=0

if [[ "${1}" != "" ]]; then
	ANSWER=${1}
fi
cat example${WHICH}.txt | ./${WHICH}
TEST=$(cat example${WHICH}.txt | ./${WHICH})
echo "${TEST}"
VAL=$(echo "${TEST}" | grep "ANSWER" | awk '{print $2}')
validateNumber $VAL $ANSWER