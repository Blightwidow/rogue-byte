#include "sly2.h"
struct Cm { char pad[0x60]; QW row[3]; QW pos; };
extern "C" {
void DecomposeSphere(QW, float *, float *, int);
void LoadRotateMatrixPanTilt(void *, float, float);
void UpdateCmMat4(Cm *);
void __as__6VECTORG9VU_VECTOR(void *, QW);
void SetCmLookAt(Cm *pcm, float dradPan, float dradTilt, QW posEye, QW posTarget)
{
    struct { QW mat[3]; float radPan; float radTilt; QW eye; } l;
    QW diff;
    QW *prow = pcm->row;
    l.eye = posEye;
    asm("lqc2 vf2, %1\n\tqmtc2.ni %2, vf1\n\tvsub.xyzw vf1, vf1, vf2\n\tqmfc2.ni %0, vf1" : "=r" (diff) : "m" (l.eye), "r" (posTarget));
    DecomposeSphere(diff, &l.radPan, &l.radTilt, 0);
    LoadRotateMatrixPanTilt(l.mat, l.radPan + dradPan, l.radTilt + dradTilt);
    __as__6VECTORG9VU_VECTOR(&pcm->pos, l.eye);
    pcm->row[0] = l.mat[0];
    prow[1] = l.mat[1];
    prow[2] = l.mat[2];
    ((int *)&prow[1])[3] = 0;
    ((int *)&prow[2])[3] = 0;
    ((int *)&prow[0])[3] = 0;
    ((float *)&prow[3])[3] = 1.0f;
    UpdateCmMat4(pcm);
}
}
