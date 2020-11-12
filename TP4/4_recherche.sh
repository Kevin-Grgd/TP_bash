#!/usr/bin/env bash

base="./CarnetsDeVoyage"
#echo $base

condition=$(ls $base | grep 19[7-9][0-9][_-][A-Z].*)
#echo $condition

cd $base

taille_max=0

for nom in $condition
do
    if [ -d $nom ]
    then
        taille=$(du -s $nom | cut -f1);
        #echo $nom
        #echo $taille
        if [ $taille -gt $taille_max ]
        then
            nom_max=$nom
            taille_max=$taille
        fi
    fi
done

echo $nom_max
       