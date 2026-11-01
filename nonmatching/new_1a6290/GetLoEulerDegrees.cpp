#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
struct Frame_1A6340 { QW dead[1]; };
extern "C" float *PmatLoWorld();
extern "C" QW DecomposeRotateMatrixEuler(float *pmat);
extern "C" QW GetLoEulerDegrees()
{
    Frame_1A6340 frame;
    QW euler = DecomposeRotateMatrixEuler(PmatLoWorld());
    QW upper;
    asm("pextuw %0, $0, %1" : "=r" (upper) : "r" (euler));
    float z = Lane(upper) * 57.295776f;
    float x = Lane(euler) * 57.295776f;
    float y = Lane(__builtin_prot3w(euler)) * 57.295776f;
    QW low = __builtin_pextlw(Word(y), Word(x));
    QW result = __builtin_pcpyld(Word(z), low);
    frame.dead[0] = result;
    return result;
}
