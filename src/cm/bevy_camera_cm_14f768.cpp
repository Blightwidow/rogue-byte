#include "sly2.h"
struct Cm { char pad0[0x60]; QW row[3]; QW pos; char pad1[0x100 - 0xA0]; char matProj[0x520]; float sStereo; };
struct Mat4 { QW row[4]; };
extern "C" {
void __as__6VECTORG9VU_VECTOR(void *, QW);
void CombineEyeLookAtProj(Mat4 *, void *, void *);
}
void BuildCmEyeMat(Cm *pcm, int nEye, void *pmatProj, void *pmatWorldToClip, Mat4 *pmatEye)
{
    float dsEye = 0.0f;
    switch (nEye) {
    case 1: dsEye = pcm->sStereo; break;
    case 2: dsEye = -pcm->sStereo; break;
    }
    QW *prow = pcm->row;
    struct { QW a; QW b; } junk;
    QW posEye;
    asm("lqc2 vf2, %1\n\tqmtc2.ni %2, vf3\n\tlqc2 vf1, %3\n\tvadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf2, vf3x\n\tsqc2 vf3, %4\n\tqmfc2.ni %0, vf1\n\tsqc2 vf1, %5"
        : "=r" (posEye) : "m" (pcm->row[1]), "r" (dsEye), "m" (pcm->pos), "m" (junk.b), "m" (junk.a));
    __as__6VECTORG9VU_VECTOR(&pmatEye->row[3], posEye);
    pmatEye->row[0] = pcm->row[0];
    pmatEye->row[1] = prow[1];
    pmatEye->row[2] = prow[2];
    ((int *)&pmatEye->row[1])[3] = 0;
    ((int *)&pmatEye->row[2])[3] = 0;
    ((int *)&pmatEye->row[0])[3] = 0;
    ((float *)&pmatEye->row[3])[3] = 1.0f;
    if (pmatProj == 0)
        pmatProj = pcm->matProj;
    CombineEyeLookAtProj(pmatEye, pmatProj, pmatWorldToClip);
}
