#!/bin/bash

# Check for ./qn
echo "Checking executable..."
if [ -f ./qn ]
then
	echo "Copying ./qn to /usr/bin..."
	cp ./qn /usr/bin
	echo "Done!"
	exit 0
else
	echo "Error: File ./qn does not exist. Did you forget to compile?"
	exit 1
fi