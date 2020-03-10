#!/bin/bash

<<KOMENTARZ
Deskryptory

0 - standardowe wejscie
1 - standardowe wyjscie
2 - standardowe wyjsice bledow

KOMENTARZ

#Przyklad 1 (utworzenie pliku z zawartoscia. najpierw tworzy plik)
ls > nowyplik.txt #plik bedzie zawieral pliki z komendy ls


#Przyklad 2 (utworzenie pliku z zawartoscia wykorzystujac deskryptor
#exec 1 > "plik1.txt" #utworzenie deskryptora
#ls > &1 #to co ls zostanie przekierowane na nasz deskryptor wyjsciowy a pozniej do pliku plik1.txt

#Przyklad 3 (polaczenie 2 plikow w calosc)
echo "Witaj w Slackware" > plik1.txt
echo "Powtorka z bash" > plik2.txt
cat plik1.txt plik2.txt > plik12.txt

#Przyklad 4 (dopisywanie danych do pliku)
# > napisuje ,  >> dopisuje
echo "Cwiczenia" >> plik12.txt

#Przyklad 5 (przekierowanie strumieni)
#exec 2>&1 #strumien bledu przekierowany na 1
#echo 'Tejstujemy' > /dev/null >&2

#Przyklad 6 (potoki)
ls -a | grep ".txt" #wszystkie pliki z ls -a z rozszerzeniem .txt

#Przyklad 7 (potoki nazwane) - trzeba zakomentować wczesniejesze execi
mkfifo myPipe #tworzenie potoku
ls -a > myPipe #wynik ls przekierowany do naszego potoku
grep ".txt" < myPipe #interesuja nasz wszystkie pliki ".txt" , z potoku zostaje to wyswietlone