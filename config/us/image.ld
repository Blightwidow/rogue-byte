/* The retail layout of the two loaded segments: file offset 0x80 -> 0x100000 ... SCUS_973.16 section table. */
SECTIONS {
    . = 0x100000;
    .text : { */text.o(.text) }
    . = 0x259df0;
    .vutext : { */vutext.o(.data) }
    . = 0x262380;
    .rodata : { */rodata.o(.data) }
    . = 0x2ac880;
    .data : { */data.o(.data) }
    . = 0x2dd250;
    .irxgap : { */irx_gap.o(.data) }
    . = 0x472200;
    .irx : { */irx.o(.data) }
    /DISCARD/ : { *(*) }
}
