#include "sly2.h"
extern "C" {
void *PredictXfTransform(void *, int, float, void *, int);
QW PosLoWorld(void *);
extern float g_2dded0;
}
struct Attach { char pad[0x30]; QW posLocal; };
struct Mat { QW row0; QW row1; QW row2; QW row3; };
struct SVT { char pad[0x100]; short delta; short idx; void *(*fn)(void *, Attach *); };
struct SoObj { char pad[0xC]; SVT *vt; };
int func_001423A0(char *jt)
{
    if (*(int *)(jt + 0x4C8) == 5) {
        if (*(int *)(jt + 0x4D4)) {
            Attach attach;
            Mat mat;
            QW posAttach;
            int chain;
            float distance;
            SoObj *obj = *(SoObj **)(jt + 0x934);
            void *xf = obj->vt->fn((char *)obj + obj->vt->delta, &attach);
            PredictXfTransform(xf, 0, 0.0f, &mat, 0);
            asm("lqc2 vf3, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3\n\tlqc2 vf4, %4\n\tlqc2 vf5, %5\n\tvmulax.xyz ACC, vf5, vf4x\n\tvmadday.xyz ACC, vf3, vf4y\n\tvmaddaz.xyz ACC, vf2, vf4z\n\tvmaddw.xyz vf6, vf1, vf0w"
                : "=r" (chain) : "m" (mat.row1), "m" (mat.row2), "m" (mat.row3), "m" (attach.posLocal), "m" (mat.row0));
            asm("sqc2 vf6, %0" : "=m" (posAttach) : "r" (chain));
            QW pos = PosLoWorld(*(void **)(jt + 0x934));
            asm("qmtc2.ni %1, vf2" : "=r" (chain) : "r" (pos));
            asm("lqc2 vf3, %1" : "+r" (chain) : "m" (posAttach));
            asm("vsub.xyzw vf1, vf2, vf3\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "+r" (chain));
            asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "+r" (chain));
            asm("qmfc2.ni %0, vf1\n\tnop" : "=r" (distance) : "r" (chain));
            if (5.0f < distance)
                return 0;
            if (*(int *)(jt + 0x9A4) != 1)
                return 1;
            if (g_2dded0 < *(float *)(*(char **)(jt + 0x994) + 0x1C))
                return 0;
        }
    }
    return 1;
}
