@echo off
IF EXIST build del build\*.* /Q
IF NOT EXIST build mkdir build
cl65 --cpu 65c02 -t none -C .\os.cfg -o .\build\os.bin .\src\main.c .\src\video.c .\src\reset_vec.s
echo Build complete: build\os.bin
