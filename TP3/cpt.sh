#!/usr/bin/env bash

# traite le cas dans lequel les arguments du script sont erronés
if (( $# != 1 )) || [[ -f $1 ]]
then
    echo "Usage: ./cpt.sh < Fichier non existant>" >&2 # &2 est la sortie d'erreur
    exit 1 # Un code de retour d'erreur
fi

# Corps du script
# On met 0 dans le fichier
echo 0 > $1;

while true
do
# La valeur contenu dans le fichier est stockée dans n
    n=`cat $1`;
# Utilisation de la commande expr & écriture
    n=`expr $n + 1`;
    echo $n > $1;
    sleep 1;
done
# Le script s'est exécuté correctement
# Le script renvoie un code de retour indiquant que tout s'est bien passé
exit 0
