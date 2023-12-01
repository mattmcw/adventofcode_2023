#!/bin/bash

set -e

g++ -std=c++11 -o 02 02.cpp


function run () {
	cat input.txt | ./02
}

time run