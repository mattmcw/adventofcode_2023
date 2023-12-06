#!/bin/bash

set -e

WHICH="01"

if [[ "${1}" != "" ]]; then
	WHICH="02"
fi

function run () {
	cat input.txt | ./${WHICH}
}

time run