#!/bin/bash

# Verify ./src folder contents
echo "Checking source files..."
ec=0
if [ ! -f ./src/main.c ]
then
	echo "==>main.c     N"
	ec=1
else
	echo "==>main.c     Y"
fi
if [ ! -f ./src/config.c ]
then
	echo "==>config.c   N"
	ec=1
else
	echo "==>config.c   Y"
fi
if [ ! -f ./src/config.h ]
then
	echo "==>config.h   N"
	ec=1
else
	echo "==>config.h   Y"
fi
if [ ! -f ./src/datetime.c ]
then
	echo "==>datetime.c N"
	ec=1
else
	echo "==>datetime.c Y"
fi
if [ ! -f ./src/datetime.h ]
then
	echo "==>datetime.h N"
	ec=1
else
	echo "==>datetime.h Y"
fi
if [ ! -f ./src/style.c ]
then
	echo "==>style.c    N"
	ec=1
else
	echo "==>style.c    Y"
fi
if [ ! -f ./src/style.h ]
then
	echo "==>style.h    N"
	ec=1
else
	echo "==>style.h    Y"
fi
if [ ! -f ./src/io.c ]
then
	echo "==>io.c       N"
	ec=1
else
	echo "==>io.c       Y"
fi
if [ ! -f ./src/io.h ]
then
	echo "==>io.h       N"
	ec=1
else
	echo "==>io.h       Y"
fi
if [ $ec -ne 0 ]
then
	echo "Error: One or more source files are missing."
	exit 1;
fi

#Check if gcc is installed???

# Compile and Link
if [ -d ./src/obj ]
then
	rm -frd ./src/obj
fi
mkdir ./src/obj
echo "Compiling..."
gcc -c ./src/main.c -o ./src/obj/main.o
gcc -c ./src/config.c -o ./src/obj/config.o
gcc -c ./src/datetime.c -o ./src/obj/datetime.o
gcc -c ./src/style.c -o ./src/obj/style.o
gcc -c ./src/io.c -o ./src/obj/io.o
echo "Linking..."
gcc ./src/obj/main.o ./src/obj/config.o ./src/obj/datetime.o ./src/obj/style.o ./src/obj/io.o -o qn
echo "Done!"