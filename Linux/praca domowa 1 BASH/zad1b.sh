#!/bin/bash

echo "[PODAJ SCIEZKE DO FOLDERU LUB KONKRETNEGO PLIKU]"
read path
echo "$path"

echo
echo "[NA CZYM OPERACJE]"
echo
echo "0 - foldery"
echo "1 - pliki"
read operation
if [ $operation -eq 0 ]; then
	echo "1) CREATE(utworz folder)"
	echo "2) REMOVE(usun folder)"
	echo "3) COPY(skopiowac folder)"
	echo "4) MOVE(przenies folder)"

	read statement
	case $statement in
		1) echo "[podaj nazwe folderu:]"
		read name
		mkdir "$path/$name"
		;;
		2) rm -r "$path"
		;;
		3) echo "[gdzie skopiowac?]"
		read wheretocopy
		cp -R "$path" "$wheretocopy"
		;;
		4) echo "[gdzie przeniesc?]"
		read wheretomove
		mv "$path" "$wheretomove"
		;;	
	esac
else
	echo "1) CREATE(utworz plik)"
	echo "2) REMOVE(usun plik)"
	echo "3) COPY(skopiowac plik)"
	echo "4) MOVE(przenies plik)"

	read statement
	case $statemtnt in
		1) echo "[podaj nazwe pliku:]"
		read name
		touch "$path/$name"
		;;
		2) rm $path
		;;
		3) echo "[gdzie skopiowac?]"
		read wheretocopy
		cp "$path" "$wheretocopy"
		;;
		4) echo "[gdzie przeniesc?]"
		read wheretomove
		mv "$path" "$wheretomove"
		;;
	esac
fi
