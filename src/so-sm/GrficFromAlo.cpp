int GrficFromAlo(int palo, int grftak)
{
    int grfic = 0;
    int a0 = palo + 0x110;
    int t0 = 0;
    int a2 = 0;
    int a3 = 1;
    while (1)
    {
        int v0 = a3 & grftak;
        if (v0 != 0)
        {
            int v1 = *(const unsigned char *)(a0 + a2);
            t0 = t0 | v1;
        }
        a2 = a2 + 1;
        v0 = a2 < 0x1A;
        if (v0 == 0)
        {
            break;
        }
        a3 = a3 << 1;
    }
    return t0;
}
