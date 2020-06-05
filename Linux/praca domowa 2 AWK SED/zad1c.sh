#!/bin/bash

#Wersja z jedną grupą, pozostałe grupy to CTRL+C CTRL+V i zmiana wartości
awk -F ","  ' BEGIN{ 
	for(i=1; i<=5; i++) for(j=1; j<=8; j++) if(j%2==0){tab[i,j]=999;} else {tab[i,j]=0;}	
}
{
	gsub("\"","",$0);
	if($2=="group A")
	{
	      	if( $1=="female")
		{
			if($7>tab[1,1])
				tab[1,1]=$7;
			if($7<tab[1,2])
				tab[1,2]=$7;
			if($8>tab[1,3])
				tab[1,3]=$8;
			if($8<tab[1,4])
				tab[1,4]=$8;
		}
		else
		{
			if($7>tab[1,5])
				tab[1,5]=$7;
			if($7<tab[1,6])
				tab[1,6]=$7
			if($8>tab[1,7])
				tab[1,7]=$8;
			if($8<tab[1,8])
				tab[1,8]=$8;
		}
	}
} END{ print "GROUP A\n--------\nREADING\nNajlepsza dziewczyna: " tab[1,1] "\nNajgorsza dziewczyna: " tab[1,2] "\nNajlepszy chlopak: " tab[1,5] "\nNajgorszy chlopak: " tab[1,6] "\nWRITING\nNajlepsza dziewczyna: " tab[1,3] "\nNajgorsza dziewczyna: " tab[1,4] "\nNajlepszy chlopak: " tab[1,7] "\nNajgorszy chlopak: " tab[1,8]} ' StudentsPerformance.csv
