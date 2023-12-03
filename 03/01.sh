#!/bin/bash

set -e

function run () {
	cat inputtest.txt | ./01
}

time run