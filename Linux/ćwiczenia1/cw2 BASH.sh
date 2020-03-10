#!bin/bash

#Wczytywanie danych z klawiatury
echo "Jaki jest twoj ulubiony kolor?"
read kolor
echo "Twoj ulubiony kolor to: $kolor"

echo

#To polecenie wyświetli zmienną 'odp',  bo nigdzie nie zapisujemy wczytywania
echo "Jaki jest twoj nick?"
odp="tata"
read
echo "$odp"

echo

echo "Podaj 3 liczby:"
read a b c
echo "Liczba w zmiennej a to: $a"
echo "Liczba w zmiennej b to: $b"
echo "Liczba w zmiennej c to: $c"

echo

#Dopisywanie danych(chodzi o ${liczba}-ty
echo "Podaj liczbe od 4 do 10: "
read liczba
echo "Jestes ${liczba}-ty w kolejce"

echo

#Wybrane parametry read
#1) -p (znak zachety bez zbanku konczacego nowej linii, wejście nie przechodzi do nowej linii)
read -p "Witaj " imie
echo "$imie"

echo

#2) -a (przypisywanie kolejnych wartosci do kolejnych indeksow zmiennej tablicowej)
echo "Podaj elementy tablic: "
read -a tablica
echo "${tablica[*]}"

#3) -e (brak nazwy zmiennej -> zmienna ta zapisywane jest do $REPLY)
echo "Witaj BASH"
read -echo
echo "$REPLY"

#4) -s (nie wyswietla  znakow wpisywanych przez uzytkownika)
# -t (30sekund na wprowadzenie hasla i po 30sekundach wyswietlanie)
read -p "Haslo: " -s -t 30 haslo
echo "$haslo"
