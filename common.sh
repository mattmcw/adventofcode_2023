#!/bin/bash

function validateNumber () {
	if [ $1 -eq $2 ]; then
		echo "Test passed $1 != $2"
	else
		echo "Test failed $1 != $2"
	fi
}


function validateString () {
	if [[ "$1" -eq "$2" ]]; then
		echo "Test passed \"$1\" != \"$2\""
	else
		echo "Test failed \"$1\" != \"$2\""
	fi
}