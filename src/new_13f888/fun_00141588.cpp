#include "sly2.h"
struct JT {
    char pad0[0x208]; void *psurface;
    char pad1[0x238 - 0x20C]; float z238;
    char pad2[0x248 - 0x23C]; float z248;
    char pad3[0x2DC - 0x24C]; int state;
    char pad4[0xF50 - 0x2E0]; int sub; int subActive;
    char pad5[0x1048 - 0xF58]; float dz1048; float dz104C;
};
struct GLOBS { char pad0[0x260]; JT *pjt; char pad1[0x300 - 0x264]; int f300; };
extern GLOBS B_002DDF40;
extern "C" void func_0019E9D8(void *);
extern "C" QW PosLoWorld(JT *);
void func_00141588(JT *pjt, VECTOR *ppos)
{
    if (pjt->subActive != -1) {
        func_0019E9D8(&pjt->sub);
        return;
    }
    *(QW *)ppos = PosLoWorld(pjt);
    float z;
    if (pjt->psurface != 0) {
        z = pjt->z238 + pjt->dz1048;
    } else {
        if (pjt->state == 0x14 || B_002DDF40.f300 != 0 || B_002DDF40.pjt != pjt) {
            ppos->z = ppos->z + (pjt->z248 + pjt->dz1048);
            return;
        }
        z = pjt->dz104C;
    }
    ppos->z = z;
}
