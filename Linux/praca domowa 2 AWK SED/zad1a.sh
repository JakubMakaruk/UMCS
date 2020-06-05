#!/bin/bash

awk -F ","  ' BEGIN{count=0} {
	gsub("\"","",$0);
	if($1=="female" && $6>60)
	{
		print $1 " " $6;
		count++;
	}
	} END{ print count } ' StudentsPerformance.csv
