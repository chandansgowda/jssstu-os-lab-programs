#!/bin/bash

read -p "Enter number>> " num
num=`echo $num`
numrev=`echo $num | rev`

if [ $num == $numrev ]
then
	echo "Palindrome"
else
	echo "Not a palindrome"
fi 
