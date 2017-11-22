#!/bin/bash

#
# Badgerloop Controls Team
#
# Authors: Vaughn Kottler
#

if [ "$#" -ne 1 ]; then
	echo "Must give processor name"
	exit 1
fi

echo "PROC = $1" > config.mk
