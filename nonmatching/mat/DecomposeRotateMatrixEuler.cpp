#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct Frame_11BFF0 { QW dead[1]; };
extern "C" float GLimitAbs__Fff(float, float);
extern "C" float asinf(float);
extern "C" float atan2f(float, float);
static inline QW Euler(float x, float y, float z)
{
    QW low = __builtin_pextlw(Word(y), Word(x));
    return __builtin_pcpyld(Word(z), low);
}
extern "C" QW DecomposeRotateMatrixEuler(float *pmat)
{
    Frame_11BFF0 frame;
    QW result;
    float eulY = asinf(GLimitAbs__Fff(-pmat[2], 1.0f));
    if (eulY < 1.5706964f) {
        if (-1.5706964f < eulY) {
            float a = atan2f(pmat[6], pmat[10]);
            float b = atan2f(pmat[1], pmat[0]);
            result = Euler(a, eulY, b);
        } else {
            float b = atan2f(-pmat[4], -pmat[8]);
            result = Euler(0.0f, eulY, b);
        }
    } else {
        float b = atan2f(-pmat[4], pmat[8]);
        result = Euler(0.0f, eulY, b);
    }
    frame.dead[0] = result;
    return result;
}
