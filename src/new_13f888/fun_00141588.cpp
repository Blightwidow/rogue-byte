#include "sly2.h"
#include "jt.h"
struct GLOBS { char pad0[0x260]; JT *pjt; char pad1[0x300 - 0x264]; int f300; };
extern GLOBS B_002DDF40;
extern "C" void func_0019E9D8(void *);
extern "C" QW PosLoWorld(JT *);
void func_00141588(JT *pjt, VECTOR *ppos)
{
    if (pjt->field_0xF54 != -1) {
        func_0019E9D8(&pjt->field_0xF50);
        return;
    }
    *(QW *)ppos = PosLoWorld(pjt);
    float z;
    if (pjt->psoSurface != 0) {
        z = pjt->field_0x238 + pjt->field_0x1048;
    } else {
        if (pjt->jmpState == 0x14 || B_002DDF40.f300 != 0 || B_002DDF40.pjt != pjt) {
            ppos->z = ppos->z + (pjt->field_0x248 + pjt->field_0x1048);
            return;
        }
        z = pjt->field_0x104C;
    }
    ppos->z = z;
}
