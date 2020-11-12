#!/usr/bin/env bash

base="./CarnetsDeVoyage"
#echo $base

condition=$(ls $base | grep 19[7-9][0-9][_-][A-Z].*)
#echo $condition

cd $base

for nom in $condition
do
    if [ -d $nom ]
    then
        echo $nom
    fi
done

       