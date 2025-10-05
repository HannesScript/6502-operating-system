@echo off
IF EXIST build del build\*.* /Q
IF NOT EXIST build mkdir build

REM Just to get an assembly file for debugging and other stuff
cc65 --cpu 65c02 src/video.c src/main.c src/vectors.asm src/crt0_min.asm -o build/os.asm

REM Use cl65 so the runtime and libc are linked automatically, and emit a map file
cl65 -v -t none --cpu 6502 -C ./os.cfg -Oirs ^
  -Wl -m,./build/os.map ^
  -o ./build/os.bin ^
  ./src/main.c ./src/video.c ./src/vectors.asm ./src/crt0_min.asm

echo Build complete: build\os.bin
echo Assembly file for debugging: build\os.asm
echo Map: build\os.map
