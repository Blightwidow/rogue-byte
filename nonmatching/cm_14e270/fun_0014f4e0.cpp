#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct CM { char pad[0x60]; QW mat[4]; };
struct LOCALS { QW matNew[4]; QW vecEuler; MATRIX3 matRotate; };
extern "C" void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(MATRIX3 *, QW);
extern "C" void SetCmPosMat(CM *, QW *);
extern "C" void func_0014F4E0(CM *pcm, QW vecDegrees)
{
    register QW zeroReg asm("$0");
    float z = Lane(__builtin_pextuw(zeroReg, vecDegrees));
    float x = Lane(vecDegrees);
    float y = Lane(__builtin_prot3w(vecDegrees));
    const float rDegToRad = 0.0174532942f;
    LOCALS l;
    float zr = z * rDegToRad;
    float yr = y * rDegToRad;
    float xr = x * rDegToRad;
    l.matNew[0] = pcm->mat[0];
    l.matNew[1] = pcm->mat[1];
    l.matNew[2] = pcm->mat[2];
    l.matNew[3] = pcm->mat[3];
    QW low = __builtin_pextlw(Word(yr), Word(xr));
    l.vecEuler = __builtin_pcpyld(Word(zr), low);
    LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&l.matRotate, l.vecEuler);
    l.matNew[0] = ((QW *)&l.matRotate)[0];
    l.matNew[1] = ((QW *)&l.matRotate)[1];
    l.matNew[2] = ((QW *)&l.matRotate)[2];
    ((float *)&l.matNew[0])[3] = 0.0f;
    ((float *)&l.matNew[1])[3] = 0.0f;
    ((float *)&l.matNew[2])[3] = 0.0f;
    return SetCmPosMat(pcm, l.matNew);
}
