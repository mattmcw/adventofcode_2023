#!/bin/bash

source ../common.sh

set -e

g++ -std=c++11 -o 01 01.cpp

ANSWER=8
#cat example01.txt | ./01
TEST=$(cat example01.txt | ./01)

validateNumber $TEST $ANSWER