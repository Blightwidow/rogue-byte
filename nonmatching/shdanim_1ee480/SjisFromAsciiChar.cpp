struct SjisRange { unsigned short w0; unsigned short w1; };
extern "C" SjisRange D_002C3728[];
extern "C" SjisRange D_002C36A0[];

unsigned int SjisFromAsciiChar(unsigned int ch, int irange)
{
    unsigned int result;
    register int isymbolBase asm("$3");
    isymbolBase = 0;
    int range = irange;
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
        { result = 0; goto done; }
    }
    if (isymbolBase == 0)
        { result = (D_002C3728[range].w0 + c - D_002C3728[range].w1) & 0xFFFF; goto done; }
    int  off;
    off = isymbolBase + 0x1F;
    asm("" : "+r" (off));
    return D_002C36A0[c - off].w0;
done:
    return result;
}
