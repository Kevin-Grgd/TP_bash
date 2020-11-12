#!/usr/bin/env bash

# traitement des cas invalides
if (( $# != 2 )) || [[ -d $1 ]] ||  [[ ! -f $1 ]]
then
    echo "Usage: ./decoupe_ligne.sh <fichier> <n>" >&2 #&2 sortie d'erreur
    exit 1
fi


while read line
do
    #    echo -e "$line"
    echo $line | cut -d' ' -f $2
done < $1



#for mot in $(cat $1);
#do
#    echo "$mot";
#done

exit 0
       
         