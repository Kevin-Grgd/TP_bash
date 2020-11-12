#!/usr/bin/env bash

#traitement des cas invalides
if (( $# != 1 )) || [[ -d $1 ]]
then
    echo "Usage: ./tee.sh <fichier>" >&2 #sortie d'erreur
    exit 1
fi

while read
do
    echo -e "$REPLY"
    echo -e "$REPLY" >> $1
done

exit 0