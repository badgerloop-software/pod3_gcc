# Badgerloop Controls: Bare-metal Firmware

*Authors: Vaughn Kottler, Cooper Green*

## Development Instructions

* Run `./configure.sh <PROC_NAME>` to create config file that sets up a make  
variable that points to `proc/<PROC_NAME>` so that the appropriate source
and header files are included for compiling and linking
* Modify source code, run `make` to attempt to build the project and  
`make install` to upload it to the board
  * If a new processor is being supported, this step may not work and the  
scripts needed to enable this functionality will need to be written

## Project Structure

TODO

## Processor Directory Structure

TODO

