#include "sly2.h"
struct M3A { float m[3][4]; } __attribute__((aligned(16)));
struct JOY {
    char pad[0x103C];
    float xLeft, yLeft;
    char pad2[0x1070 - 0x1044];
    float xRight, yRight;
    char pad3[0x10B4 - 0x1078];
    unsigned grfbtnA;
    char pad4[0x10BC - 0x10B8];
    unsigned grfbtnB;
};
struct PO { char pad[0x154]; unsigned forced; };
struct VJOY {
    char pad[0x10];
    float xLeft, yLeft, radLeft, sLeft;
    float xRight, yRight, radRight, sRight;
    unsigned grfbtn;
    char pad2[0x40 - 0x34];
    M3A mat;
    char pad3[0x7C - 0x70];
    PO *ppo;
    int vjoym;
};
extern int g_2dfbc0;
extern JOY B_002DFC00;
extern JOY B_002E0D00;
extern char g_2ddfa0;
extern "C" void ResetVjoy(VJOY *);
extern "C" void UpdateVjoyStick(float, VJOY *, float *, float *, float *, float *, float *);
extern "C" void UpdateVjoyPressTimes(VJOY *);
extern "C" void LoadRotateMatrixPanTilt(M3A *, float, float);
extern "C" void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(MATRIX3 *, float *, float *);
struct Locals { M3A mat; float radPan; float radTilt; };
void UpdateVjoy(VJOY *pvjoy)
{
    Locals l;
    float zero;
    asm("mtc1 $0, %0" : "=f"(zero));
    l.radTilt = zero;
    l.radPan = zero;
    switch (pvjoy->vjoym) {
    case 0:
        ResetVjoy(pvjoy);
        break;
    case 1: {
        JOY *pjoy = (g_2dfbc0 & 2) ? &B_002DFC00 : &B_002E0D00;
        pvjoy->xLeft = pjoy->xLeft;
        pvjoy->yLeft = pjoy->yLeft;
        pvjoy->xRight = pjoy->xRight;
        pvjoy->yRight = pjoy->yRight;
        pvjoy->grfbtn = (pjoy->grfbtnA & ~pjoy->grfbtnB) | pvjoy->ppo->forced;
        DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1((MATRIX3 *)&g_2ddfa0, &l.radPan, &l.radTilt);
    }
    }
    LoadRotateMatrixPanTilt(&l.mat, l.radPan, l.radTilt);
    pvjoy->mat = l.mat;
    UpdateVjoyStick(l.radPan, pvjoy, &pvjoy->xLeft, &pvjoy->yLeft, &pvjoy->radLeft, &pvjoy->sLeft, (float *)((char *)pvjoy + 0x70));
    UpdateVjoyStick(l.radPan, pvjoy, &pvjoy->xRight, &pvjoy->yRight, &pvjoy->radRight, &pvjoy->sRight, (float *)((char *)pvjoy + 0x74));
    UpdateVjoyPressTimes(pvjoy);
}
