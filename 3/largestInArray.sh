#!/bin/bash

declare -a arr

read -p "Array Size>> " size

for((i=0;i<$size;i++))
do
	read -p "arr[$i] : " ele
	arr[$i]=$ele
done

big=${arr[0]}

for((i=1;i<$size;i++))
do
	if [ ${arr[$i]} -ge $big ]
	then
		big=${arr[$i]}
	fi
done

echo "Largest Number in array : $big"
