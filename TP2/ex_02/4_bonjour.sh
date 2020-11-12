#!/usr/bin/env bash


nb_param=1

if [ $# == 0 ]
then
    echo Que la force soit avec vous !
else
    for param in "$@"
    do
        nb_param=$(( nb_param + 1 ));
        if [ $nb_param == 2 ]
        then
            echo Bonjour $param !;
            nb_param=0;
        fi;
    done;
fi;
