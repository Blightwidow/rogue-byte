int GrficFromAlo(int palo, int grftak)
{
    const unsigned char *table = (const unsigned char *)(palo + 0x110);
    int grfic = 0;
    int index = 0;
    int bit = 1;
    do {
        if (bit & grftak) {
            grfic |= table[index];
        }
        index++;
        bit <<= 1;
    } while (index < 0x1A);
    return grfic;
}
