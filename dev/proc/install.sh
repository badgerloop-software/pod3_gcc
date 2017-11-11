#!/bin/bash

# ST-Link V2
if [ -d "/media/$USERNAME/NODE_L432KC" ]; then
	cp e2c.bin /media/$USERNAME/NODE_L432KC
	echo "Copying e2c.bin to /media/$USERNAME/NODE_L432KC"
# J-Link
else
	JLinkExe -device STML432KC -if SWD -speed 4000 -autoconnect 1 -CommanderScript ./proc/flash.jlink
fi

