# Badgerloop Pod Firmware

A bare-metal, multi-target GCC build for the Badgerloop pod.

*Contributors: Vaughn Kottler, Cooper Green*

## Workstation Setup

A Debian-based Linux workstation is recommended, builds are not tested  
on any other operating systems.

The primary developers use [Ubuntu GNOME 16.04 LTS](https://ubuntugnome.org/).

1. Install `gcc-arm-none-eabi`, `gdb-arm-none-eabi`, `make`

   `sudo apt-get install gcc-arm-none-eabi gdb-arm-none-eabi make`

1. Clone Pod III Documentation

   `git clone https://github.com/badgerloop-software/pod3_documentation`

2. Execute `clone_others.sh`

   `cd pod3_documentation && ./clone_others.sh`

3. Follow the [instructions](https://github.com/texane/stlink/blob/master/doc/compiling.md)  
to compile the [stlink](https://github.com/texane/stlink) repo from source

   Make sure to install everything they have listed.

   If something goes wrong, you can `make clean` to start over.

4. Copy build outputs (`st-flash`, `st-info`, `st-util`) to `~/bin` and make sure that's on your `$PATH`
5. Follow the instructions under [Permissions with udev](https://github.com/texane/stlink/blob/master/doc/compiling.md)

## Build commands

Must be invoked via `make`.

Invoking `make` by itself will compile all sources to created `bare_metal.bin`.

* `install`

   Attempt to flash `bare_metal.bin` to the configured device, if connected.

* `debug`

   Flash the configured device and execute the commands necessary to enter  
a GDB session.

* `dump`

   Open the disassembled ELF output in Vim.

* `clean`

   Delete project build objects and outputs.

## Current Limitations

Right now the `main` thread of execution is an empty while loop. This build  
does not currently do anything useful. It is ready to be developed on,  
however.
