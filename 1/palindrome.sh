#!/bin/bash

read -p "Enter string>> " str1
str2=`echo $str1 | rev`

if [ $str1 == $str2 ]
then
	echo "Palindrome"
else
	echo "Not a palindrome"
fi


:'
Additional Info:
We can use 
lowerstr=$(echo $s | tr "[:upper:]" "[:lower:]") 
to covert given string to lowercase
'
