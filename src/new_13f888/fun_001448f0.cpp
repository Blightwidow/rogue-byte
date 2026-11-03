#include "sly2.h"
struct JT;
struct RESCUE {
    JT *pjt;
    int pad4[3];
    QW pos;
    float dist;
    float distMax;
    int fActive;
};
extern "C" QW PosLoWorld(JT *);
extern const float D_002BD2D8;
extern const float D_002BD2D0;
extern "C" float g_2dded0;
static inline float Distance(QW from, QW to)
{
    QW delta;
    QW one;
    float distance;
    asm("vsub.xyzw %0, %1, %2" : "=j" (delta) : "j" (from), "j" (to));
    asm("vmul.xyz %0, %0, %0\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "+j" (delta), "=j" (one));
    asm("vsqrt Q, %0x\n\tvwaitq\n\tvaddq.x %0, vf0, Q" : "+j" (delta));
    asm("qmfc2.ni %0, %1" : "=r" (distance) : "j" (delta));
    return distance;
}
static inline int DistanceBits(QW from, QW to)
{
    QW delta;
    QW one;
    int distance;
    asm("vsub.xyzw %0, %1, %2" : "=j" (delta) : "j" (from), "j" (to));
    asm("vmul.xyz %0, %0, %0\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "+j" (delta), "=j" (one));
    asm("vsqrt Q, %0x\n\tvwaitq\n\tvaddq.x %0, vf0, Q" : "+j" (delta));
    asm("qmfc2.ni %0, %1" : "=r" (distance) : "j" (delta));
    return distance;
}
void func_001448F0(RESCUE *self, QW posNew)
{
    if (self->fActive == 0) {
        int tooClose = Distance(self->pos, posNew) < D_002BD2D8;
        if (!tooClose) {
            self->pos = posNew;
            QW posJt = PosLoWorld(self->pjt);
            *(int *)&self->dist = DistanceBits(posJt, self->pos);
            self->distMax = g_2dded0 + D_002BD2D0;
        }
    }
}
