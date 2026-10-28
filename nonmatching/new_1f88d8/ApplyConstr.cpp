#include "sly2.h"
#define RET { register QW r asm("$2"); asm("qmfc2.ni %0, vf4" : "=r" (r)); return r; }
struct CONSTR { QW normal; int ct; };
extern "C" QW ApplyConstr(CONSTR *pconstr, QW vec)
{
    int ct = pconstr->ct;
    asm("qmtc2.ni %0, vf4" : : "r" (vec));
    switch (ct) {
    case 3:
        asm("vsub.xyzw vf4, vf0, vf0");
        RET
    case 2:
        asm("lqc2 vf1, %0\n\tvmul.xyz vf2, vf4, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvmulx.xyzw vf4, vf1, vf2x" : : "m" (pconstr->normal));
        RET
    case 1:
        asm("lqc2 vf1, %0\n\tvmul.xyz vf2, vf4, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvmulx.xyzw vf2, vf1, vf2x\n\tvsub.xyzw vf4, vf4, vf2" : : "m" (pconstr->normal));
        break;
    }
    RET
}
