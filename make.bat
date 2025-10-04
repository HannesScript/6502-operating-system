@echo off
IF EXIST build del build\*.* /Q
IF NOT EXIST build mkdir build

REM Use cl65 so the runtime and libc are linked automatically, and emit a map file
cl65 -v -t none --cpu 6502 -C ./os.cfg -Oirs ^
  -Wl -m,./build/os.map ^
  -o ./build/os.bin ^
  ./src/main.c ./src/video.c ./src/vectors.s ./src/crt0_min.s

echo Build complete: build\os.bin
echo Map: build\os.map
