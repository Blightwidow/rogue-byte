void ClearLoGrfField(char *self, unsigned bits)
{
    unsigned field = *(unsigned *)(self + 0x40);
    if (!(field & 1)) {
        *(unsigned *)field &= ~bits;
        return;
    }
    *(unsigned *)(self + 0x40) = field & ~bits;
}
