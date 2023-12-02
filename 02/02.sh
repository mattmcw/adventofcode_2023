#!/bin/bash

set -e

function run () {
	cat input.txt | ./02
}

time run