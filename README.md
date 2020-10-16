# Dictionary purge dupes

Small tool to purge dupes from dictionary files. Look at `testfiles/dictionnary_1.txt` to see if you need it.

## Supported Platforms

- Windows (tested with vs2019 toolchain)
- Linux

## Building

Go to `headers/const.h` and change `MAX_RAM_ALLOCATION` and `LINE_MAX_LEN` to fit with your config.  

``` shell
mkdir build
cd build
cmake ..
make
```
## Usage
``` shell
 ./purge_dupes dic_to_purge output_file
```