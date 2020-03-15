#!/bin/bash

case $1 in

	"-hd") df -h
		;;
	"-ram") free -m
		;;
	"-cpu") ps -A #lub dac top
		;;
	"-all") df -h
		echo
		free -m
		echo
		ps -U root
		;;
esac
