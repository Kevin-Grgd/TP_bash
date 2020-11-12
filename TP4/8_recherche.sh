#!/usr/bin/env bash

base="./CarnetsDeVoyage"
#echo $base

condition=$(ls $base | grep 19[7-9][0-9][_-][A-Z].*)
#echo $condition


taille_max=0

for nom in $condition
do
    if [ -d $base/$nom ]
    then
        taille=$(du -s $base/$nom | cut -f1);
        #echo $nom
        #echo $taille
        if [ $taille -gt $taille_max ]
        then
            nom_max=$nom
            taille_max=$taille
        fi
    fi
done

echo Repertoire : $nom_max
echo #Saut de ligne pour plus de clarté (ds le terminal)

resultat=$(find $base/$nom_max -type f -name "*Itineraire*")

for cherche_bilbon in $resultat
do
    grep -q "Bilbon" $cherche_bilbon > /dev/null
    if [ $? = 0 ]
    then
        fichier_cle=$cherche_bilbon
        echo $fichier_cle
    fi
done

echo #Saut de ligne pour plus de clarté (ds le terminal)

grep "à" $fichier_cle | sort | head -n 3 | cut -c1 | tr -d "\n"

echo #Saut de ligne pour plus de clarté (ds le terminal)
echo #Saut de ligne pour plus de clarté (ds le terminal)

grep '[[:alpha:]]' $fichier_cle | sort -k3,3