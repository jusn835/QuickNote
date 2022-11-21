#!/bin/bash

# Check if qn is already installed in /usr/bin
if [ -f /usr/bin/qn ]
then
	echo "Removing /usr/bin/qn..."
	rm /usr/bin/qn
	if [ -f ~/.qnrc ]
	then
		echo "Removing ~/.qnrc..."
		rm -f ~/.qnrc
	fi
	echo "Done!"
else
	echo "Error: QuickNote is not installed."
fi