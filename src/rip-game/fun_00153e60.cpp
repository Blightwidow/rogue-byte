#include "sly2.h"
extern QW g_2a2dc0;
struct SENSOR { char pad[0xE0]; void *anchor; };
extern "C" QW PosLoWorld(void *);
extern "C" int FIsBasicDerivedFrom(void *, int);

QW func_00153E60(SENSOR *psensor)
{
    QW result;
    void *anchor = psensor->anchor;
    if (!anchor) {
        result = PosLoWorld(psensor);
    } else if (!FIsBasicDerivedFrom(anchor, 0x38)) {
        result = PosLoWorld(psensor->anchor);
    } else {
        QW pos = PosLoWorld(psensor->anchor);
        float lift = 80.0f;
        QW lifted;
        asm volatile("" : "+f" (lift));
        asm("qmtc2.ni %3, vf3\n\tmfc1 $4, %4\n\tqmtc2.ni $4, vf2\n\tlqc2 vf1, %2\n\tsqc2 vf2, %0\n\tvadda.xyzw ACC, vf0, vf3\n\tvmaddx.xyzw vf3, vf1, vf2x\n\tqmfc2.ni %1, vf3" : "=m" (lifted), "=r" (result) : "m" (g_2a2dc0), "r" (pos), "f" (lift) : "$4");
    }
    return result;
}
