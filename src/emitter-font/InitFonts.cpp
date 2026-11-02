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
    for (int index = 0; index < 2; index++) { int flag = D_002BE320[index]; func_0015F710(&B_002DE770[index], flag, &zpr); }
}
