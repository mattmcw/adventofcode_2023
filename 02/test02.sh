#!/bin/bash

source ../common.sh

set -e

g++ -std=c++11 -o 02 02.cpp

ANSWER=2286

#cat example02.txt | ./02

TEST=$(cat example02.txt | ./02)

validateNumber $TEST $ANSWER