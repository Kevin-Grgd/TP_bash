#!/usr/bin/env bash


if [ $# == 0 ]
then
    echo Que la force soit avec vous !
else
    for param in "$@"
    do
        echo Bonjour $param !;
    done;
fi;

