#!/bin/bash

#WERSJA ZE WSZYSTKIMI GRUPAMI
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
	if($2=="group B")
	{
	      	if( $1=="female")
		{
			if($7>tab[2,1])
				tab[2,1]=$7;
			if($7<tab[2,2])
				tab[2,2]=$7;
			if($8>tab[2,3])
				tab[1,3]=$8;
			if($8<tab[2,4])
				tab[2,4]=$8;
		}
		else
		{
			if($7>tab[2,5])
				tab[2,5]=$7;
			if($7<tab[2,6])
				tab[2,6]=$7
			if($8>tab[2,7])
				tab[2,7]=$8;
			if($8<tab[2,8])
				tab[2,8]=$8;
		}
	}
	if($2=="group C")
	{
	      	if( $1=="female")
		{
			if($7>tab[3,1])
				tab[3,1]=$7;
			if($7<tab[3,2])
				tab[3,2]=$7;
			if($8>tab[3,3])
				tab[3,3]=$8;
			if($8<tab[3,4])
				tab[3,4]=$8;
		}
		else
		{
			if($7>tab[3,5])
				tab[3,5]=$7;
			if($7<tab[3,6])
				tab[3,6]=$7
			if($8>tab[3,7])
				tab[3,7]=$8;
			if($8<tab[3,8])
				tab[3,8]=$8;
		}
	}
	if($2=="group D")
	{
	      	if( $1=="female")
		{
			if($7>tab[4,1])
				tab[4,1]=$7;
			if($7<tab[4,2])
				tab[4,2]=$7;
			if($8>tab[4,3])
				tab[4,3]=$8;
			if($8<tab[4,4])
				tab[4,4]=$8;
		}
		else
		{
			if($7>tab[4,5])
				tab[4,5]=$7;
			if($7<tab[4,6])
				tab[4,6]=$7
			if($8>tab[4,7])
				tab[4,7]=$8;
			if($8<tab[4,8])
				tab[4,8]=$8;
		}
	}
	if($2=="group E")
	{
	      	if( $1=="female")
		{
			if($7>tab[5,1])
				tab[5,1]=$7;
			if($7<tab[5,2])
				tab[5,2]=$7;
			if($8>tab[5,3])
				tab[5,3]=$8;
			if($8<tab[5,4])
				tab[5,4]=$8;
		}
		else
		{
			if($7>tab[5,5])
				tab[5,5]=$7;
			if($7<tab[5,6])
				tab[5,6]=$7
			if($8>tab[5,7])
				tab[5,7]=$8;
			if($8<tab[5,8])
				tab[5,8]=$8;
		}
	}
} END{ print 
"GROUP A\n--------\nREADING\nNajlepsza dziewczyna: " tab[1,1] "\nNajgorsza dziewczyna: " tab[1,2] "\nNajlepszy chlopak: " tab[1,5] "\nNajgorszy chlopak: " tab[1,6] "\nWRITING\nNajlepsza dziewczyna: " tab[1,3] "\nNajgorsza dziewczyna: " tab[1,4] "\nNajlepszy chlopak: " tab[1,7] "\nNajgorszy chlopak: " tab[1,8] "\nGROUP B\n--------\nREADING\nNajlepsza dziewczyna: " tab[2,1] "\nNajgorsza dziewczyna: " tab[2,2] "\nNajlepszy chlopak: " tab[2,5] "\nNajgorszy chlopak: " tab[2,6] "\nWRITING\nNajlepsza dziewczyna: " tab[2,3] "\nNajgorsza dziewczyna: " tab[2,4] "\nNajlepszy chlopak: " tab[2,7] "\nNajgorszy chlopak: " tab[2,8] "\nGROUP C\n--------\nREADING\nNajlepsza dziewczyna: " tab[3,1] "\nNajgorsza dziewczyna: " tab[3,2] "\nNajlepszy chlopak: " tab[3,5] "\nNajgorszy chlopak: " tab[3,6] "\nWRITING\nNajlepsza dziewczyna: " tab[3,3] "\nNajgorsza dziewczyna: " tab[3,4] "\nNajlepszy chlopak: " tab[3,7] "\nNajgorszy chlopak: " tab[3,8] "\nGROUP C\n--------\nREADING\nNajlepsza dziewczyna: " tab[4,1] "\nNajgorsza dziewczyna: " tab[4,2] "\nNajlepszy chlopak: " tab[4,5] "\nNajgorszy chlopak: " tab[4,6] "\nWRITING\nNajlepsza dziewczyna: " tab[4,3] "\nNajgorsza dziewczyna: " tab[4,4] "\nNajlepszy chlopak: " tab[4,7] "\nNajgorszy chlopak: " tab[4,8] "\nGROUP D\n--------\nREADING\nNajlepsza dziewczyna: " tab[5,1] "\nNajgorsza dziewczyna: " tab[5,2] "\nNajlepszy chlopak: " tab[5,5] "\nNajgorszy chlopak: " tab[5,6] "\nWRITING\nNajlepsza dziewczyna: " tab[5,3] "\nNajgorsza dziewczyna: " tab[5,4] "\nNajlepszy chlopak: " tab[5,7] "\nNajgorszy chlopak: " tab[5,8] } ' StudentsPerformance.csv
