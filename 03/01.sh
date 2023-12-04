#!/bin/bash

set -e

function run () {
	cat input.txt | ./01
}

time run