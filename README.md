# 65c02 Computer OS

Hi there! This is an open source operating system for [Ben Eater's 6502 Computer](https://eater.net/6502). This OS is written in C and some 6502 Assembly and compiled + assembled with the cc65 compiler using it's compiler and assembler. For building the OS just run the `make.bat` file on Windows, on Linux and MacOS you just have to copy the commands inside and run them. Please make sure that all the file references are correct when using Linux or MacOS!

## Specialitys

This OS needs a special setup with an **Arduino Mega** always reading the address and data lines, to read data from the 65c02. If the Mega reads, that the 65c02 is **writing to $3ff1 in RAM**, it knows, that it should write the 8-bit pixel color to a 320*200 pixel screen. I am planning to change this method of displaying to an RGB-screen in some time, but I have a really low budget and not enough experience and time to immediatly start with this kind of displaying. I have some ideas to use a seperate [video card from Ben Eater (the "worlds worst video card" in his own words)](https://eater.net/vga), but it currently a little to expensive for me to use.
