#!bin/bash - na ubuntu œcie¿ka do basha
#!user/bin/bash - na innych dystrybucjach

#Komentarz

#Deklaracja zmiennych
a="Pierwsza zmienna"
echo $a

#Apostrofy
echo 'Tekst: $a'
echo "Tekst: $a"
echo "Tekst
echo `ls -a`
echo "ls -a"
echo

#alternatynwa metoda wykonywania polecenia
echo $(ls -a)
echo

#Rodzaje zmiennych
#zmienne lokalne
b="Zmienna lokalna"
katalog=`pwd`
echo "Jestes w katalogu $katalog"

#zmienne specjalne
echo "$0"
echo "$@"
echo "$?" #kod powrotu ostatnio wykonanego polecenia
echo "$$" #PID procesu bie¿¹cej pow³oki 

#zmienne lokalne
#NOWA PODPOW£OKA -> bash
#WYJŒCIE Z PODPOW£OKI -> exit
#t="Tekst"
#echo "$t"
#bash
#echo "$t"

#zmienna globalna
export t="Tekst"
export -n zmienna #usuwanie zmiennej globalnej
echo $(export -p) #wyswietlanie zmiennych globalnych
echo `env` #wyswietlanie zmiennych srodowiskowych

echo

#zmienne tablicowe
tablica=(1 2 3 4 5 6)
echo ${tablica[0]} #pierwszy element
echo ${tablica[*]} #wszystkie elementy
echo ${tablica[@]} #wszystkie elementy(to samo co *)

echo ${#tablica[0]} #liczba znakow danego elementu tablicy

#dodawanie elementow do tablicy
tablic[6]=7
echo ${tablica[*]}

tab[0]="TAK"
tab[1]="NIE"
echo ${tab[@]}

#usuwanie elementow tablicy
unset tablica[3]
echo ${tablica[@]}

#usuwanie calej tablicy
unset tablica[*]
echo ${tablica[@]}