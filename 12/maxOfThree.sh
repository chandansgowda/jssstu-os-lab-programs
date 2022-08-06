#!/bin/bash

echo "Enter three numbers (space seperated): "
read a b c

echo -n "Largest Number: "
if [ $a -ge $b -a $b -ge $c ]
then
	echo "$a"
elif [ $b -ge $a -a $a -ge $c ]
then
	echo "$b"
else
	echo "$c"
fi
	
