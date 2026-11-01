#include "sly2.h"
static inline QW Word1A6340(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
static inline float Lane1A6340(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
extern "C" float *PmatLoWorld();
extern "C" QW DecomposeRotateMatrixEuler(float *pmat);
extern "C" QW GetLoEulerDegrees()
{
    register QW zeroReg asm("$0");
    QW euler = DecomposeRotateMatrixEuler(PmatLoWorld());
    float z = Lane1A6340(__builtin_pextuw(zeroReg, euler)) * 57.295776f;
    float x = Lane1A6340(euler) * 57.295776f;
    float y = Lane1A6340(__builtin_prot3w(euler)) * 57.295776f;
    QW low = __builtin_pextlw(Word1A6340(y), Word1A6340(x));
    return __builtin_pcpyld(Word1A6340(z), low);
}
