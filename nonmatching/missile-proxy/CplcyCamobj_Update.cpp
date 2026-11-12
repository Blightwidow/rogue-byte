#include "sly2.h"
#include "vu0inline.h"
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
        M4 *mat = &l.mat;
        QW row0 = m[0];
        QW negone = VectorFromFloat(-1.0f);
        l.copy[0] = row0;
        QW row1 = m[1];
        l.copy[1] = row1;
        QW negX = VectorScaleX(row0, negone);
        QW row2 = m[2];
        QW negZ = VectorScaleX(row2, negone);
        l.rowY = row1;
        l.negone = negone;
        l.negZ = negZ;
        l.negX = negX;
        l.copy[2] = row2;
        QW pos = PosLoWorld(camobj);
        __as__6VECTORG9VU_VECTOR(&mat->row[3], pos);
        mat->row[0] = l.negZ;
        mat->row[1] = l.negX;
        mat->row[2] = l.rowY;
        ((int *)&l.mat.row[3])[-1] = 0;
        ((int *)&l.mat.row[2])[-1] = 0;
        ((int *)&l.mat.row[1])[-1] = 0;
        ((float *)&mat->row[3])[3] = 1.0f;
        SetCmPosMat(B_002DDF40, mat);
    }
    if (camobj->hasFov > 0) {
        float fov = 2.0f * atanf(17.995901f / camobj->focal);
        if (!(fov >= 0.01f))
            fov = 0.01f;
        else if (3.0f < fov)
            fov = 3.0f;
        SetCmFov(B_002DDF40, fov);
    }
}
