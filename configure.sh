#!/bin/bash

# Read in device family
echo "Device families: " && ls proc
read -t 10 -p "Which device family? " DEV_FAM

# Read in processor
echo "Processors: " && ls proc/$DEV_FAM 2>/dev/null
if [ $? -eq 2 ]; then
	echo "'$DEV_FAM' not found."
	exit 1
fi

read -t 10 -p "Which processor? " PROC_CHOICE

# Verify processor dir exists
ls proc/$DEV_FAM/$PROC_CHOICE >/dev/null 2>/dev/null
if [ $? -eq 2 ]; then
	echo "'$PROC_CHOICE' not found."
	exit 1
fi

rm -f cfg
ln -s proc/$DEV_FAM/$PROC_CHOICE cfg
echo "Project configured for $DEV_FAM$PROC_CHOICE."
