#include "sly2.h"
extern QW g_2a2db0;
struct S4 { float x, y, z, w; };
extern "C" QW bevy_player_p14_1c4768(char *pvjoy, QW vec)
{
    QW *rows = (QW *)(pvjoy + 0x40);
    S4 s;
    float length;
    asm("lqc2 vf3, 0x20(%0)\n\tlqc2 vf1, 0x10(%0)" : : "r" (rows));
    asm("lqc2 vf2, %0" : : "m" (((QW *)pvjoy)[4]));
    QW dflt = g_2a2db0;
    asm("qmtc2.ni %0, vf8\n\tvmul.xyzw vf6, vf2, vf8\n\tvmaxw.xyzw vf7, vf0, vf0w\n\tvmul.xyzw vf5, vf1, vf8\n\tvmul.xyzw vf4, vf3, vf8\n\tvadday.x ACC, vf6, vf6y\n\tvmaddz.x vf2, vf7, vf6z\n\tvaddax.y ACC, vf5, vf5x\n\tvmaddz.y vf2, vf7, vf5z\n\tvaddax.z ACC, vf4, vf4x\n\tvmaddy.z vf2, vf7, vf4y" : : "r" (vec));
    float eps = 0.0001f;
    asm("sqc2 vf2, %0" : "=m" (s) : "f" (eps));
    float b = s.z;
    float a = s.y;
    s.z = 0.0f;
    s.y = b;
    s.x = -a;
    asm("lqc2 vf3, %0" : : "m" (s));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    register int bits asm("$3");
    asm("qmfc2.ni %0, vf1" : "=r" (bits));
    asm("mtc1 %1, %0\n\tnop" : "=f" (length) : "r" (bits));
    if (length < eps) {
        asm("qmtc2.ni %0, vf1" : : "r" (dflt));
    } else {
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
    }
    register QW result asm("$2");
    asm("qmfc2.ni %0, vf1" : "=r" (result));
    return result;
}
