#!/bin/bash

awk -F ","  ' BEGIN{sum_f=0; sum_m=0; count_f=0; count_m=0} {
	gsub("\"","",$0);
	if($1=="female")
	{
		sum_f+=$7;
		count_f++;
	}
	else
	{
		sum_m+=$7;
		count_m++;
	}
	} END{ print "Średni wynik dziewcząt:" sum_f/count_f "\n Średni wynik chłopców:" sum_m/count_m } ' StudentsPerformance.csv
