// SPDX-License-Identifier: GPL-3.0-or-later
struct CProg { char b[0x70]; };
struct RGBA { int v; } __attribute__((aligned(16)));
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
    CProg prog; RGBA argba0; RGBA argba1; RGBA argba2; RGBA argba3;
    argba0.v = 0x807F0000;
    argba1.v = 0x803F3F3F;
    argba2.v = 0x80003F3F;
    argba3.v = 0x8000003F;
    __5CProgP4RGBAN31(&prog, &argba0, &argba1, &argba2, &argba3);
    printf(RO_002A6A58, D_STR_002C46D8, D_STR_002C46C0, 0x2B0);
    func_001C2A78(1);
    Begin__5CProg(&prog);
    long fAfterGs = 0;
    for (unsigned istep = 0; istep < 0x13; istep++) {
        MarkClockTick__FP5CLOCK(g_2dded0, 1);
        if (fAfterGs)
            SetRemain__5CProgi(&prog, 0x13 - istep);
        else if (D_002BFCE0[istep] == StartupGs__Fv)
            fAfterGs = 1;
        D_002BFCE0[istep]();
    }
    SetRemain__5CProgi(&prog, 0);
    End__5CProg(&prog);
    func_001C2BA8(1);
}
