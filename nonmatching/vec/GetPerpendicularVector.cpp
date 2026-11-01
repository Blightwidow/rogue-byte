#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct Frame_11E390 { QW dead[1]; };
extern "C" QW GetPerpendicularVector(QW vec)
{
    Frame_11E390 frame;
    float x = Lane(vec);
    float y = Lane(__builtin_prot3w(vec));
    QW upper;
    asm("pextuw %0, $0, %1" : "=r" (upper) : "r" (vec));
    float z = Lane(upper);
    float absX = __builtin_fabsf(x);
    float absY = __builtin_fabsf(y);
    float absZ = __builtin_fabsf(z);
    float zero = 0.0f;
    QW helper;
    if (absX <= absY) {
        if (absX <= absZ) {
            QW low = __builtin_pextlw(Word(z), Word(zero));
            helper = __builtin_pcpyld(Word(-y), low);
        } else {
            QW low = __builtin_pextlw(Word(-x), Word(y));
            helper = __builtin_pcpyld(Word(zero), low);
        }
    } else if (absY <= absZ) {
        QW low = __builtin_pextlw(Word(zero), Word(z));
        helper = __builtin_pcpyld(Word(-x), low);
    } else {
        QW low = __builtin_pextlw(Word(-x), Word(y));
        helper = __builtin_pcpyld(Word(zero), low);
    }
    asm volatile("qmtc2.ni %0, vf1" : : "r" (helper));
    frame.dead[0] = helper;
    QW result;
    asm("qmtc2.ni %1, vf2\n\tvopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf1, vf1, vf2\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf3, vf1, Q\n\tqmfc2.ni %0, vf3" : "=r" (result) : "r" (vec));
    return result;
}
