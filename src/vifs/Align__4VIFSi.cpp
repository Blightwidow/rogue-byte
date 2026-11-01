struct VIFS { char pad[0xC]; int addr; };
void Align__4VIFSi(VIFS *pvifs, int align)
{
    int addr = pvifs->addr;
    int phase = (unsigned)(addr & 0xC) >> 2;
    int *pcur = (int *)addr;
    while (phase != align) {
        *pcur++ = 0;
        phase = (phase + 1) % 4;
    }
    pvifs->addr = (int)pcur;
}
