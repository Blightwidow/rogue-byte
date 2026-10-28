#include "sly2.h"
struct Camobj { char pad[0xE0]; void *target; char pad1[0x44]; float focal; int hasFov; };
struct Cplcy { char pad[0x10]; Camobj *camobj; };
struct M4 { QW row[4]; };
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
extern "C" void CplcyCamobj_Update(Cplcy *self)
{
    Camobj *camobj = self->camobj;
    void *pcm;
    if (camobj->target) {
        QW eye = PosLoWorld(camobj);
        QW tgt = PosLoWorld(camobj->target);
        pcm = B_002DDF40;
        SetCmLookAt(pcm, 0.0f, 0.0f, eye, tgt);
    } else {
        QW *m = PmatLoWorld(camobj);
        QW copy[3];
        QW negZ, negX, rowY;
        M4 mat;
        QW negone;
        pcm = B_002DDF40;
        int bits;
        float nf = -1.0f;
        asm("mfc1 %0, %1" : "=r" (bits) : "f" (nf));
        asm("lqc2 vf1, %0" : : "m" (m[0]));
        copy[0] = m[0];
        asm("qmtc2.ni %0, vf2" : : "r" (bits));
        QW r1 = m[1];
        asm("vmulx.xyzw vf4, vf1, vf2x");
        copy[1] = r1;
        asm("lqc2 vf3, %0" : : "m" (m[2]));
        asm("vmulx.xyzw vf1, vf3, vf2x");
        rowY = r1;
        asm("sqc2 vf2, %0" : "=m" (negone));
        asm("sqc2 vf1, %0" : "=m" (negZ));
        asm("sqc2 vf4, %0" : "=m" (negX));
        asm("sqc2 vf3, %0" : "=m" (copy[2]));
        QW pos = PosLoWorld(camobj);
        __as__6VECTORG9VU_VECTOR(&mat.row[3], pos);
        mat.row[0] = negZ;
        mat.row[1] = negX;
        mat.row[2] = rowY;
        ((int *)&mat.row[2])[3] = 0;
        ((int *)&mat.row[1])[3] = 0;
        ((int *)&mat.row[0])[3] = 0;
        ((float *)&mat.row[3])[3] = 1.0f;
        SetCmPosMat(pcm, &mat);
    }
    if (camobj->hasFov > 0) {
        float fov = 2.0f * atanf(17.995901f / camobj->focal);
        if (fov < 0.01f)
            fov = 0.01f;
        else if (3.0f < fov)
            fov = 3.0f;
        SetCmFov(pcm, fov);
    }
}
