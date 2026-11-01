struct VIFS { char pad0[0xC]; unsigned *pcur; char pad1[0x1C - 0x10]; int flag; };
extern "C" int D_002C4430[];
extern "C" int VIFS_AddUnpackCommand(VIFS *pvifs, int a, int b, int c)
{
    unsigned word;
    if (a >= 0x10) {
        a &= 0xF;
        word = 0x60008000;
    } else {
        word = 0x6000C000;
    }
    word = word | (a << 24) | (b << 16) | c;
    if (pvifs->flag != 0)
        word |= 0x10000000;
    unsigned *pcur = pvifs->pcur;
    pvifs->pcur = pcur + 1;
    *pcur = word;
    return D_002C4430[a] * b;
}
