#!/bin/bash
# PRZYKŁAD W TERMINALU: 
# echo "Ala ma kota" | ./zad5.sh Ala Maciek
# lub
# ./zad5.sh Ala Maciek
# Ala ma kota

read string

function modify(){
	echo ${string/$1/$2}
}

modify $1 $2 
echo
