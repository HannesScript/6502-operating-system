.export __START__

.import _main                 ; C entry point
.import initlib, donelib      ; constructors/destructors
.import zerobss, copydata     ; BSS/DATA init
.import _exit                 ; program exit
.import __STACKSTART__        ; provided by linker config
.importzp c_sp                ; C stack pointer in zero page

.segment "STARTUP"
__START__:
    ; Set up the C stack pointer
    lda #<(__STACKSTART__+1)
    sta c_sp
    lda #>(__STACKSTART__+1)
    sta c_sp+1

    ; Initialize BSS and DATA and run constructors
    jsr zerobss
    jsr copydata
    jsr initlib

    ; Call main()
    jsr _main

    ; Run destructors and exit
    jsr donelib
    jmp _exit
