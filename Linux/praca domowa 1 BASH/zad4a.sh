#!/bin/bash
#Uruchom zad4a.sh, a za pomoca zad4b.sh mozesz zamknac proces.

echo $$ > endlessScript.pid

while true
do
	echo "Nacisnij CTRL+C zeby zatrzymac!"
	sleep 1
done
