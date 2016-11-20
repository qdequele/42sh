#!/bin/bash

while [ 1 ]
do
	clear
	if [ $(leaks 42sh | wc -l) != "19" ]; then
		say leaks
	fi
	sleep 2
done
