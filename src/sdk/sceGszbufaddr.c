extern unsigned long *func_002405F0();

short sceGszbufaddr(short psm, short width, short height)
{
    int blocksWide;
    int blocksHigh;
    unsigned long *mode;

    mode = func_002405F0();
    blocksWide = (width + 63) / 64;
    if (psm & 2) {
        blocksHigh = (height + 63) / 64;
    } else {
        blocksHigh = (height + 31) / 32;
    }
    if ((*mode & 0xFFFF0000FFFFUL) == 1) {
        return blocksWide * blocksHigh;
    }
    return blocksWide * blocksHigh * 2;
}
