#include "sly2.h"
struct JOY { char pad0[0x18]; float angle; float mag; };
struct LO;
struct JT { char pad0[0x150]; JOY *pjoy; char pad1[0x10DC - 0x154]; LO *pfocus; };
struct ORBIT { JT *pjt; char pad[8]; int side; };
extern "C" {
QW SetVectorCylind__FP6VECTORfff(float, float, float);
QW PosLoWorld(void *);
}
int bevy_player_p25_1374f0(ORBIT *porbit)
{
    float zero = 0.0f;
    if (zero < porbit->pjt->pjoy->mag) {
        if (porbit->pjt->pfocus == 0)
            return porbit->side;
        struct { QW dir; QW saved; } l;
        l.dir = SetVectorCylind__FP6VECTORfff(porbit->pjt->pjoy->angle - 1.5707964f, 1.0f, zero);
        QW posFocus = PosLoWorld(porbit->pjt->pfocus);
        int t0;
        asm volatile("qmtc2.ni %1, vf1" : "=r" (t0) : "r" (posFocus));
        asm("sqc2 vf1, %0" : "=m" (l.saved) : "r" (t0));
        QW posJt = PosLoWorld(porbit->pjt);
        int bits;
        asm volatile("qmtc2.ni %2, vf2\n\tlqc2 vf1, %1\n\tvsub.xyzw vf1, vf1, vf2\n\tlqc2 vf3, %3\n\tvmul.xyz vf1, vf3, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (bits) : "m" (l.saved), "r" (posJt), "m" (l.dir));
        float dot = *(float *)&bits;
        int result = 0;
        if (zero < dot) {
        } else {
            result = 1;
        }
        return result;
    }
    return porbit->side;
}
