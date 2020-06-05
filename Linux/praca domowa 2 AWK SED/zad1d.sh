#!/bin/bash

awk -F ","  ' BEGIN{count=0} {
	gsub("\"","",$0);
	if($1=="male" && ($6==100 || $7==100 || $8==100))
	{
		count++;
	}
	} END{ print count } ' StudentsPerformance.csv
