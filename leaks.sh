#!/bin/bash

while [ 1 ]
do
	clear
	leaks 42sh
	if [ $(leaks 42sh | wc -l) == "2" ]; then
		say not started
	elif [ $(leaks 42sh | wc -l) != "19" ]; then
		say likse
	fi
	sleep 2
done
