#!/usr/bin/env bash

if [ $# != 2 ] || [ $2 == 0 ]
then
    echo "usage : division <entier1> <entier2_non_nul>"
    echo "affiche  le quotient de <entier1> par <entier2>"
else
    echo quotient : $(($1/$2))
fi;
