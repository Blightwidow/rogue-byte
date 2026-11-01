#include "sly2.h"
struct Camobj { char pad[0xE0]; void *target; char pad1[0x44]; float focal; int hasFov; };
struct Cplcy { char pad[0x10]; Camobj *camobj; };
struct M4 { QW row[4]; };
struct Locals12E858 { QW copy[3]; QW negZ; QW negX; QW rowY; M4 mat; QW negone; };
extern char B_002DDF40[];
extern "C" {
QW PosLoWorld(void *);
QW *PmatLoWorld(void *);
void SetCmLookAt(void *, float, float, QW, QW);
void SetCmPosMat(void *, M4 *);
void SetCmFov(void *, float);
void __as__6VECTORG9VU_VECTOR(void *, QW);
float atanf(float);
}
// lane 0 of a QW from an FP constant
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void CplcyCamobj_Update(Cplcy *self)
{
    Camobj *camobj = self->camobj;
    if (camobj->target) {
        QW eye = PosLoWorld(camobj);
        QW tgt = PosLoWorld(camobj->target);
        SetCmLookAt(B_002DDF40, 0.0f, 0.0f, eye, tgt);
    } else {
        QW *m = PmatLoWorld(camobj);
        Locals12E858 l;
        asm("lqc2 vf1, %0" : : "m" (m[0]));
        l.copy[0] = m[0];
        asm("qmtc2.ni %0, vf2" : : "r" (Word(-1.0f)));
        l.copy[1] = m[1];
        asm("vmulx.xyzw vf4, vf1, vf2x");
        asm("lqc2 vf3, %0" : : "m" (m[2]));
        asm("vmulx.xyzw vf1, vf3, vf2x");
        l.rowY = m[1];
        asm("sqc2 vf2, %0" : "=m" (l.negone));
        asm("sqc2 vf1, %0" : "=m" (l.negZ));
        asm("sqc2 vf4, %0" : "=m" (l.negX));
        asm("sqc2 vf3, %0" : "=m" (l.copy[2]));
        QW pos = PosLoWorld(camobj);
        __as__6VECTORG9VU_VECTOR(&l.mat.row[3], pos);
        l.mat.row[0] = l.negZ;
        l.mat.row[1] = l.negX;
        l.mat.row[2] = l.rowY;
        ((int *)&l.mat.row[2])[3] = 0;
        ((int *)&l.mat.row[1])[3] = 0;
        ((int *)&l.mat.row[0])[3] = 0;
        ((float *)&l.mat.row[3])[3] = 1.0f;
        SetCmPosMat(B_002DDF40, &l.mat);
    }
    if (camobj->hasFov > 0) {
        float fov = 2.0f * atanf(17.995901f / camobj->focal);
        if (fov < 0.01f)
            fov = 0.01f;
        else if (3.0f < fov)
            fov = 3.0f;
        SetCmFov(B_002DDF40, fov);
    }
}
