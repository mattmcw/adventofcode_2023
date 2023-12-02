#!/bin/bash

ANSWER=142
TEST=$(cat example01.txt | ./01)

if [ $ANSWER -eq $TEST ]; then
	echo "Test passed $TEST == $ANSWER"
else
	echo "Test failed $TEST != $ANSWER"
fi