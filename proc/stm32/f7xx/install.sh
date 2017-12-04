#!/bin/bash

DIRECTORY=/media/$USER/NODE_F767ZI
BINARY=bare_metal.bin 

# ST-Link V2
if [ -d "$DIRECTORY" ]; then
	cp $BINARY $DIRECTORY
	echo "Copying $BINARY to $DIRECTORY"
# J-Link
else
	echo "Device is not connected (need $DIRECTORY)."
fi
