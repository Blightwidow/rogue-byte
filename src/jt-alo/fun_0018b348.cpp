/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct XFP { char pad[0x60]; void *v; };
struct JT {
    char pad0[0x60]; void *xfRoot;
    char pad1[0x19A4 - 0x64]; XFP *part;
    char pad2[0x19C0 - 0x19A8]; void *xfC0;
    char pad3[0x19CC - 0x19C4]; void *xfCC;
    char pad4[0x1BC8 - 0x19D0]; void *aseg;
    char pad5[0x1BD8 - 0x1BCC]; float tLabel;
    char pad6[0x1BE0 - 0x1BDC]; QW p1; QW p2; QW p3; QW euler; QW local;
};
extern "C" float TFindAsegLabel__FP4ASEG3OID(void *, int);
extern "C" void PredictAsegEffect(void *, float, JT *, float, void *, void *, MATRIX4 *, MATRIX4 *);
extern "C" QW DecomposeRotateMatrixEuler(MATRIX4 *);
extern "C" void InvertMatrix4Affine(MATRIX4 *, MATRIX4 *);
extern "C" void func_0018B348(JT *pjt)
{
    MATRIX4 matA;
    MATRIX4 matB;
    MATRIX4 matC;
    MATRIX4 matInv;
    if (pjt->aseg == 0)
        return;
    float t = TFindAsegLabel__FP4ASEG3OID(pjt->aseg, 0x167);
    pjt->tLabel = t;
    PredictAsegEffect(pjt->aseg, t, pjt, 0.0f, pjt->part->v, pjt->xfRoot, &matA, 0);
    pjt->p1 = *(QW *)&matA.mat[3][0];
    PredictAsegEffect(pjt->aseg, pjt->tLabel, pjt, 0.0f, pjt->xfCC, pjt->xfRoot, &matB, 0);
    pjt->p2 = *(QW *)&matB.mat[3][0];
    PredictAsegEffect(pjt->aseg, pjt->tLabel, pjt, 0.0f, pjt->xfC0, pjt->xfRoot, &matC, 0);
    pjt->p3 = *(QW *)&matC.mat[3][0];
    pjt->euler = DecomposeRotateMatrixEuler(&matC);
    InvertMatrix4Affine(&matInv, &matC);
    asm("lqc2 vf2, %0" : : "m" (*(QW *)&matInv.mat[0][0]));
    asm("lqc2 vf4, %0" : : "m" (*(QW *)&matInv.mat[1][0]));
    asm("lqc2 vf3, %0" : : "m" (*(QW *)&matInv.mat[2][0]));
    asm("lqc2 vf1, %0" : : "m" (*(QW *)&matInv.mat[3][0]));
    asm("lqc2 vf5, %0" : : "m" (pjt->p1));
    asm("vmulax.xyz ACC, vf2, vf5x");
    asm("vmadday.xyz ACC, vf4, vf5y");
    asm("vmaddaz.xyz ACC, vf3, vf5z");
    asm("vmaddw.xyz vf2, vf1, vf0w");
    asm("sqc2 vf2, %0" : "=m" (pjt->local));
}
