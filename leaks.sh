#!/bin/bash

while [ 1 ]
do
	clear
	if [ $(leaks 42sh | wc -l) != " "]; then
    	say leaks
	fi
	sleep 5
done
