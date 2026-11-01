#include "sly2.h"
struct ACT;
struct XF;
struct Frame_226370 { QW dead[1]; };
struct TANK { char pad0[0x5C]; XF *pxf; char pad1[0x18C - 0x60]; float pan; float tilt; char pad2[0x1CC - 0x194]; int fRotAct; char pad3[8]; ACT *pact; };
extern "C" ACT *func_0012DC18(TANK *, XF *, int, int, int, QW);
extern "C" void func_0012E460(ACT **);
// Builds the vector (x, y, z, 0) from three floats: mfc1 each into a GPR, pextlw packs x,y, pcpyld adds z (lane 2).
static inline QW Euler(float x, float y, float z)
{
    QW result;
    QW low;
    asm("mfc1 %0, %1" : "=r"(low) : "f"(x));
    asm("mfc1 %0, %1" : "=r"(result) : "f"(y));
    low = __builtin_pextlw(result, low);
    asm("mfc1 %0, %1" : "=r"(result) : "f"(z));
    return __builtin_pcpyld(result, low);
}

void func_00226370(TANK *ptank, int fRotAct)
{
    Frame_226370 frame;
    if (ptank->fRotAct == fRotAct)
        return;
    ptank->fRotAct = fRotAct;
    if (fRotAct) {
        float tilt = ptank->tilt;
        float pan = ptank->pan;
        QW euler = Euler(0.0f, -tilt, pan);
        frame.dead[0] = euler;
        ptank->pact = func_0012DC18(ptank, ptank->pxf, 1, 5, 3, euler);
    } else {
        func_0012E460(&ptank->pact);
    }
}
