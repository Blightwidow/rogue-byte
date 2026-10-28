#include "sly2.h"
struct ACT;
struct XF;
struct TANK { char pad0[0x5C]; XF *pxf; char pad1[0x18C - 0x60]; float pan; float tilt; char pad2[0x1CC - 0x194]; int fRotAct; char pad3[8]; ACT *pact; };
extern "C" ACT *func_0012DC18(TANK *, XF *, int, int, int, QW);
extern "C" void func_0012E460(ACT **);
static inline QW Word(float f) { QW r; asm volatile("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
static inline QW Euler(float x, float y, float z)
{
    QW junk;
    QW low = __builtin_pextlw(Word(y), Word(x));
    QW result = __builtin_pcpyld(Word(z), low);
    junk = result;
    asm("" : : "m" (junk));
    return result;
}

void func_00226370(TANK *ptank, int fRotAct)
{
    if (ptank->fRotAct == fRotAct)
        return;
    ptank->fRotAct = fRotAct;
    if (fRotAct) {
        float tilt = ptank->tilt;
        float pan = ptank->pan;
        QW euler = Euler(0.0f, -tilt, pan);
        ptank->pact = func_0012DC18(ptank, ptank->pxf, 1, 5, 3, euler);
    } else {
        func_0012E460(&ptank->pact);
    }
}
