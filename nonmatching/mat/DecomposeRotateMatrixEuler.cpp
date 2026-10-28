#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" float GLimitAbs__Fff(float, float);
extern "C" float asinf(float);
extern "C" float atan2f(float, float);
extern "C" QW DecomposeRotateMatrixEuler(float *pmat)
{
    QW junk;
    QW result;
    float eulY = asinf(GLimitAbs__Fff(-pmat[2], 1.0f));
    if (eulY < 1.5706964f) {
        if (-1.5706964f < eulY) {
            float a = atan2f(pmat[6], pmat[10]);
            float b = atan2f(pmat[1], pmat[0]);
            QW low = __builtin_pextlw(Word(eulY), Word(a));
            result = __builtin_pcpyld(Word(b), low);
        } else {
            float b = atan2f(-pmat[4], -pmat[8]);
            QW low = __builtin_pextlw(Word(eulY), Word(0.0f));
            result = __builtin_pcpyld(Word(b), low);
        }
    } else {
        float b = atan2f(-pmat[4], pmat[8]);
        QW low = __builtin_pextlw(Word(eulY), Word(0.0f));
        result = __builtin_pcpyld(Word(b), low);
    }
    junk = result;
    asm("" : : "m" (junk));
    return result;
}
