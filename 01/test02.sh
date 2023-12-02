#!/bin/bash

ANSWER=281
TEST=$(cat example02.txt | ./02)

if [ $ANSWER -eq $TEST ]; then
	echo "Test passed $TEST == $ANSWER"
else
	echo "Test failed $TEST != $ANSWER"
fi