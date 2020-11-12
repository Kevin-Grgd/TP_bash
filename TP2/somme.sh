#!/usr/bin/env bash

res=0

for i in $@
do
    sum=$(($sum + $i))
done

echo Somme des paramètre : $sum