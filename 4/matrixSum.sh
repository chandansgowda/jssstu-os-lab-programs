#!/bin/bash

declare -a mat1
declare -a mat2
declare -a result

read -p "Enter m>> " m
read -p "Enter n>> " n

for((i=0;i<$m;i++))
do
	for((j=0;j<$n;j++))
	do
		read -p "mat1[$i,$j] : " ele
		mat1[$i,$j]=$ele
	done
done

for((i=0;i<$m;i++))
do
	for((j=0;j<$n;j++))
	do
		read -p "mat2[$i,$j] : " ele
		mat2[$i,$j]=$ele
		result[$i,$j]=$(( ${mat1[$i,$j]}+${mat2[$i,$j]} ))
	done
done

echo "Result Matrix: "
for((i=0;i<$m;i++))
do
	for((j=0;j<$n;j++))
	do
		echo -n "${result[$i,$j]} "
	done
	echo ""
done
