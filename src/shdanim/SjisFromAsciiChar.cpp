// SPDX-License-Identifier: GPL-3.0-or-later
struct SjisRange { unsigned short w0; unsigned short w1; };
extern "C" SjisRange D_002C3728[];
extern "C" SjisRange D_002C36A0[];

// Retail reads only $a0: $a1 is written before every read, so the function takes one argument (as ConvertAsciiToSjis calls it) and
// `range` is a plain uninitialised local. isymbolBase is 1 plus the number of letters and digits below the character's symbol run
// (0, 10, 36, 62), so a symbol's table index is its printable offset (c - 0x20) less those skipped characters: written that way,
// gcc keeps retail's `addiu v0,v1,0x1F; subu v0,a2,v0` instead of folding 0x1F into c. The tail is one result assigned in an
// if/else with the symbol arm first: that reproduces retail's beql to the letter/digit arm and its register choice.
extern "C" unsigned int SjisFromAsciiChar(unsigned int ch)
{
    int isymbolBase = 0;
    int range;
    unsigned int c = ch & 0xFF;
    if (c - 0x20 < 0x10) {
        isymbolBase = 1;
    } else if (c - 0x30 < 10) {
        range = 0;
    } else if (c - 0x3A < 7) {
        isymbolBase = 0xB;
    } else if (c - 0x41 < 0x1A) {
        range = 1;
    } else if (c - 0x5B < 6) {
        isymbolBase = 0x25;
    } else if (c - 0x61 < 0x1A) {
        range = 2;
    } else if (c - 0x7B < 4) {
        isymbolBase = 0x3F;
    } else {
        return 0;
    }
    unsigned int result;
    if (isymbolBase != 0)
        result = D_002C36A0[c - 0x20 - (isymbolBase - 1)].w0;
    else
        result = (D_002C3728[range].w0 + c - D_002C3728[range].w1) & 0xFFFF;
    return result;
}
