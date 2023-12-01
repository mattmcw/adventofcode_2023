#!/bin/bash

set -e

g++ -std=c++11 -o 01 01.cpp

function run () {
	cat input.txt | ./01
}

time run