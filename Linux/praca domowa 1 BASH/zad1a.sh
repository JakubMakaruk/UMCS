#!/bin/bash

case $1 in
	"crFolder") mkdir "$2/$3"
		;;
	"crFile") touch "$2/$3"
		;;
	"rm") rm -r $2
		;;
	"cp") cp $2 $3
		;;
	"mv") mv $2 $3
		;;
esac
