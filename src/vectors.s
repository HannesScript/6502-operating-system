.import __START__            ; cc65 runtime entry point

.segment "CODE"
nmi_handler:
    rti

irq_handler:
    rti

.segment "VECTORS"
    .word nmi_handler        ; NMI vector ($FFFA-$FFFB)
    .word __START__          ; RESET vector ($FFFC-$FFFD)
    .word irq_handler        ; IRQ/BRK vector ($FFFE-$FFFF)
