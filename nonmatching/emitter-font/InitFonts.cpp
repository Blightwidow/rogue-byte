struct ZPR { char pad[0x630]; };
struct FONT { char pad[0x140]; };
extern "C" void InitZpr__FP3ZPR3ZPKP2LO(ZPR *, int, int);
extern "C" void func_0015F710(FONT *, int, ZPR *);
extern "C" FONT B_002DE770[];
extern "C" int D_002BE320[];
extern "C" void InitFonts(void)
{
    ZPR zpr;
    InitZpr__FP3ZPR3ZPKP2LO(&zpr, 0x1000, 0x1800);
    FONT *font = B_002DE770; int *flags = D_002BE320;
    for (int index = 1; index >= 0; index--) { func_0015F710(font++, *flags++, &zpr); }
}
