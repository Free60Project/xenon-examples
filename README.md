# xenon-examples

Sample homebrew for the libXenon homebrew library.

## Building

1. Install [LibXenon](https://github.com/Free60Project/libxenon) on your PC.

2. Clone this git repository and enter it:
    * `git clone https://github.com/Free60Project/xenon-examples.git`
    * `cd xenon-examples`

3. Enter the directory of the example to build:
    * `cd template`

4. Run the `make` command to build!

## Running

To run homebrew built with libXenon, you need XeLL Reloaded on your console.

### Via USB

Copy the compiled .elf32 of the homebrew to the root of a FAT32 formatted USB
drive and rename it to "xenon.elf". XeLL will load this file from a USB and
your homebrew will run.

### Via TFTP

TODO
