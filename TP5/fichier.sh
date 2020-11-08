#!/usr/bin/env bash

$i
$nbPage
$acces = 'acces.txt'
$algo = 1

i=1

while(( 2**$i <= 1000 ))
do
	while(( algo < 5 ))
	do
		if (( $algo -eq 4))
			$algo=1
		fi
		nbPage=$(( 2 ** $i ))
		./main 1 $nbPage 0 $acces 
		i=$(( $i + 1 ))
	done
done