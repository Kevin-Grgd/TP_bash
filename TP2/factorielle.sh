#!/usr/bin/env bash

function factorielle() {
    (res=1;
     n=$1

     while test $n -gt 1
     do
         res=`expr $res \* $n`
         n=`expr $n - 1`
     done
     echo $1! = $res
    )
}

echo `factorielle $1`