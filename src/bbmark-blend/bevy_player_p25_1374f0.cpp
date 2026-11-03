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
        QW dir = SetVectorCylind__FP6VECTORfff(porbit->pjt->pjoy->angle - 1.5707964f, 1.0f, zero);
        QW posFocus = PosLoWorld(porbit->pjt->pfocus);
        QW posJt = PosLoWorld(porbit->pjt);
        QW diff;
        asm("vsub.xyzw %0, %1, %2" : "=j" (diff) : "j" (posFocus), "j" (posJt));
        QW dotq;
        QW one;
        asm("vmul.xyz %0, %3, %2\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "=j" (dotq), "=j" (one) : "j" (diff), "j" (dir));
        float dot;
        asm("mtc1 %1, %0" : "=f" (dot) : "r" (dotq));
        if (zero < dot)
            return 0;
        return 1;
    }
    return porbit->side;
}
