struct CProg { char b[0x70]; };
struct RGBA { int v; int pad[3]; };
extern "C" {
void __5CProgP4RGBAN31(CProg *, RGBA *, RGBA *, RGBA *, RGBA *);
void Begin__5CProg(CProg *);
void End__5CProg(CProg *);
void SetRemain__5CProgi(CProg *, int);
void func_001C2A78(int);
void func_001C2BA8(int);
void MarkClockTick__FP5CLOCK(void *, int);
void StartupGs__Fv(void);
int printf(const char *, ...);
extern char RO_002A6A58[];
extern char D_STR_002C46D8[];
extern char D_STR_002C46C0[];
extern char g_2dded0[];
extern void (*D_002BFCE0[])(void);
}
void StartupAll(void)
{
    struct { CProg prog; RGBA argba0; RGBA argba1; RGBA argba2; RGBA argba3; } l;
    l.argba0.v = 0x807F0000;
    l.argba1.v = 0x803F3F3F;
    l.argba2.v = 0x80003F3F;
    l.argba3.v = 0x8000003F;
    __5CProgP4RGBAN31(&l.prog, &l.argba0, &l.argba1, &l.argba2, &l.argba3);
    printf(RO_002A6A58, D_STR_002C46D8, D_STR_002C46C0, 0x2B0);
    func_001C2A78(1);
    Begin__5CProg(&l.prog);
    int fAfterGs = 0;
    for (unsigned istep = 0; istep < 0x13; istep++) {
        MarkClockTick__FP5CLOCK(g_2dded0, 1);
        if (fAfterGs)
            SetRemain__5CProgi(&l.prog, 0x13 - istep);
        else
        {
            fAfterGs = 1;
            if (D_002BFCE0[istep] != StartupGs__Fv)
                fAfterGs = 0;
        }
        D_002BFCE0[istep]();
    }
    SetRemain__5CProgi(&l.prog, 0);
    End__5CProg(&l.prog);
    func_001C2BA8(1);
}
