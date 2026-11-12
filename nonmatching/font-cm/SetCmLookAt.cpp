#include "sly2.h"
#include "vu0inline.h"
struct Cm { char pad[0x60]; QW row[3]; QW pos; };
extern "C" {
void DecomposeSphere(QW, float *, float *, int);
void LoadRotateMatrixPanTilt(void *, float, float);
void UpdateCmMat4(Cm *);
void __as__6VECTORG9VU_VECTOR(void *, QW);
void SetCmLookAt(Cm *pcm, float dradPan, float dradTilt, QW posEye, QW posTarget)
{
    QW mat[3];
    float radPan;
    float radTilt;
    QW *prow = pcm->row;
    QW diff = VectorSub(posTarget, posEye);
    DecomposeSphere(diff, &radPan, &radTilt, 0);
    LoadRotateMatrixPanTilt(mat, radPan + dradPan, radTilt + dradTilt);
    __as__6VECTORG9VU_VECTOR(&pcm->pos, posEye);
    pcm->row[0] = mat[0];
    prow[1] = mat[1];
    ((int *)&prow[1])[3] = 0;
    prow[2] = mat[2];
    ((int *)&prow[2])[3] = 0;
    ((int *)&prow[0])[3] = 0;
    ((float *)&prow[3])[3] = 1.0f;
    UpdateCmMat4(pcm);
}
}
