#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" QW GetPerpendicularVector(QW vec)
{
    register QW zeroReg asm("$0");
    float  x;
    float y = Lane(__builtin_prot3w(vec));
    float absX = __builtin_fabsf(x);
    x = Lane(vec);
    float z = Lane(__builtin_pextuw(zeroReg, vec));
    float absY = __builtin_fabsf(y);
    float zeroF = 0.0f;
    float absZ = __builtin_fabsf(z);
    QW helper;
    QW junk;
    if (absX <= absY) {
        if (absX <= absZ) {
            QW low = __builtin_pextlw(Word(z), Word(zeroF));
            helper = __builtin_pcpyld(Word(-y), low);
            asm("qmtc2.ni %0, vf1" : : "r" (helper));
            junk = helper;
        } else {
            QW low = __builtin_pextlw(Word(-x), Word(y));
            helper = __builtin_pcpyld(Word(zeroF), low);
            asm("qmtc2.ni %0, vf1" : : "r" (helper));
            junk = helper;
        }
    } else if (absZ < absY) {
        QW low = __builtin_pextlw(Word(-x), Word(y));
            helper = __builtin_pcpyld(Word(zeroF), low);
        asm("qmtc2.ni %0, vf1" : : "r" (helper));
        junk = helper;
    } else {
        QW low = __builtin_pextlw(Word(zeroF), Word(z));
            helper = __builtin_pcpyld(Word(-x), low);
        asm("qmtc2.ni %0, vf1" : : "r" (helper));
        junk = helper;
    }
    asm("" : : "m" (junk));
    QW result;
    asm("qmtc2.ni %1, vf2\n\tvopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf1, vf1, vf2\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf3, vf1, Q\n\tqmfc2.ni %0, vf3" : "=r" (result) : "r" (vec));
    return result;
}
