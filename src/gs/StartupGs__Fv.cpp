#include "sly2.h"
extern "C" char B_002DFB40[];
extern "C" char B_002DEB80[];
extern "C" char B_002DEDC0[];
extern "C" char B_002DF260[];
extern "C" char B_002DF010[];
extern "C" char B_002DF4B0[];
extern "C" char B_002DF700[];
extern "C" char B_002DF720[];
extern "C" int B_002DFB4C;
extern "C" int B_002DFB50;
extern "C" void InitCritSect__FP8CRITSECT(void *);
extern "C" void sceGsResetGraph(int, int, int, int);
extern "C" void sceGsSetDefDBuff(void *, int, int, int, int, int, int);
extern "C" void BuildClearGifs__FP2QWG4RGBAi(void *, unsigned *, int);
extern "C" void BuildFbaGif(int, void *, int);
extern "C" void BuildAllDrawEnvGifs();
extern "C" int NewSema(int, int);
extern "C" void AddIntcHandler(int, void (*)(int), int);
extern "C" void EnableIntc(int);
extern "C" void GS_Interrupt__Fi();
extern "C" void VBlankS_Interrupt__Fi(int);
extern "C" void ResetGs__Fv();
extern "C" void StartupGs__Fv()
{
    InitCritSect__FP8CRITSECT(B_002DFB40);
    sceGsResetGraph(0, 1, 2, 1);
    sceGsSetDefDBuff(B_002DEB80, 0, 0x200, 0xE0, 3, 0x30, 0);
    int address = (int)B_002DEB80;
    do {
        int *pmode = (int *)address;
        *pmode &= -2;
        ((unsigned char *)pmode)[1] = 0x80;
        *pmode |= 0x20;
        address += 0x28;
    } while (address < (int)B_002DEB80 + 0x50);
    unsigned color;
    color = 0x80000000;
    BuildClearGifs__FP2QWG4RGBAi(B_002DEDC0, &color, 3);
    color = 0x80000000;
    BuildClearGifs__FP2QWG4RGBAi(B_002DF260, &color, 3);
    color = 0x80000000;
    BuildClearGifs__FP2QWG4RGBAi(B_002DF010, &color, 2);
    color = 0x80000000;
    BuildClearGifs__FP2QWG4RGBAi(B_002DF4B0, &color, 1);
    BuildFbaGif(2, B_002DF700, 1);
    BuildFbaGif(2, B_002DF720, 0);
    BuildAllDrawEnvGifs();
    B_002DFB4C = NewSema(0, 1);
    B_002DFB50 = NewSema(0, 1);
    AddIntcHandler(2, VBlankS_Interrupt__Fi, 0);
    EnableIntc(2);
    AddIntcHandler(0, (void (*)(int))ResetGs__Fv, 0);
    EnableIntc(0);
    GS_Interrupt__Fi();
    *(volatile int *)0x10003010 = 0;
}
