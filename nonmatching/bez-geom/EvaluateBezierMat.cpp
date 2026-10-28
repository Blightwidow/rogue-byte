#include "sly2.h"
struct M3 { QW row[3]; };
extern "C" {
void LoadRotateMatrix(M3 *, QW);
void MatMulMatTransMat(M3 *, M3 *, M3 *);
QW DecomposeRotateMatrix(M3 *);
}
static inline void MulRowsLoad(M3 *pleft, M3 *pright)
{
    asm("lqc2 vf3, %0" : : "m" (pleft->row[0]));
    asm("lqc2 vf5, %0" : : "m" (pleft->row[1]));
    asm("lqc2 vf6, %0" : : "m" (pright->row[1]));
    asm("lqc2 vf2, %0" : : "m" (pright->row[2]));
    asm("lqc2 vf1, %0" : : "m" (pright->row[0]));
    asm("lqc2 vf4, %0" : : "m" (pleft->row[2]));
    asm("vmulax.xyz ACC, vf1, vf3x\n\tvmadday.xyz ACC, vf6, vf3y\n\tvmaddz.xyz vf3, vf2, vf3z");
    asm("vmulax.xyz ACC, vf1, vf5x\n\tvmadday.xyz ACC, vf6, vf5y\n\tvmaddz.xyz vf5, vf2, vf5z");
    asm("vmulax.xyz ACC, vf1, vf4x\n\tvmadday.xyz ACC, vf6, vf4y\n\tvmaddz.xyz vf1, vf2, vf4z");
}
static inline void MulRowsStore(M3 *pdest, M3 *pcopyA, M3 *pcopyB)
{
    asm("sqc2 vf3, %0" : "=m" (pdest->row[0]));
    asm("sqc2 vf5, %0" : "=m" (pdest->row[1]));
    asm("sqc2 vf1, %0" : "=m" (pdest->row[2]));
    asm("sqc2 vf3, %0" : "=m" (pcopyA->row[0]));
    asm("sqc2 vf3, %0" : "=m" (pcopyB->row[0]));
    asm("sqc2 vf5, %0" : "=m" (pcopyA->row[1]));
    asm("sqc2 vf5, %0" : "=m" (pcopyB->row[1]));
    asm("sqc2 vf1, %0" : "=m" (pcopyA->row[2]));
    asm("sqc2 vf1, %0" : "=m" (pcopyB->row[2]));
}
extern "C" void EvaluateBezierMat(float dt, float t, float gScale, M3 *pmatStart, QW wStart, M3 *pmatEnd, QW wEnd, M3 *pmatOut, QW *pwOut)
{
    float u = t / dt;
    float uInv = 1.0f - u;
    if (pmatOut) {
        M3 matStartAhead;
        M3 matEndBehind;
        M3 matBetween;
        M3 matRotate;
        char raw[0x40];
        M3 *pcopy1 = (M3 *)(raw + 0x10);
        M3 *pcopy2 = (M3 *)raw;
        float gEnd = u * u * uInv;
        float uCubed = u * u * u;
        int bits;
        QW scaled;
        asm("mfc1 %0, %1" : "=r" (bits) : "f" (u * uInv * uInv * dt));
        asm("qmtc2.ni %0, vf2" : : "r" (wStart));
        asm("qmtc2.ni %0, vf1" : : "r" (bits));
        asm("vmulx.xyzw vf2, vf2, vf1x");
        asm("qmfc2.ni %0, vf2" : "=r" (scaled));
        LoadRotateMatrix(&matRotate, scaled);
        float negScale = -gEnd * dt;
        MulRowsLoad(pmatStart, &matRotate);
        asm("mfc1 %0, %1" : "=r" (bits) : "f" (negScale));
        asm("qmtc2.ni %0, vf7" : : "r" (bits));
        asm("lqc2 vf2, %0" : : "m" (wEnd));
        asm("vmulx.xyzw vf2, vf2, vf7x");
        MulRowsStore(&matStartAhead, pcopy1, &matBetween);
        asm("sqc2 vf7, %0" : "=m" (raw[0]));
        asm("qmfc2.ni %0, vf2" : "=r" (scaled));
        LoadRotateMatrix(&matRotate, scaled);
        MulRowsLoad(pmatEnd, &matRotate);
        MulRowsStore(&matEndBehind, pcopy2, &matBetween);
        MatMulMatTransMat(&matBetween, &matStartAhead, &matEndBehind);
        QW between = DecomposeRotateMatrix(&matBetween);
        float weight = gEnd * (3.0f - dt) + uCubed;
        asm("mfc1 %0, %1" : "=r" (bits) : "f" (weight));
        asm("qmtc2.ni %0, vf2" : : "r" (between));
        asm("qmtc2.ni %0, vf1" : : "r" (bits));
        asm("vmulx.xyzw vf2, vf2, vf1x");
        asm("qmfc2.ni %0, vf2" : "=r" (scaled));
        LoadRotateMatrix(&matRotate, scaled);
        MulRowsLoad(&matStartAhead, &matRotate);
        MulRowsStore(pmatOut, pcopy2, &matBetween);
    }
    if (pwOut) {
        M3 matBetween;
        QW gBetweenVec;
        float gBetween = (u * (6.0f - u * 6.0f)) / dt;
        asm("mfc1 %0, %1" : "=r" (gBetweenVec) : "f" (gBetween));
        MatMulMatTransMat(&matBetween, pmatStart, pmatEnd);
        QW between = DecomposeRotateMatrix(&matBetween);
        int bitsScale;
        asm("mfc1 %0, %1" : "=r" (bitsScale) : "f" (gScale));
        int bitsStart;
        asm("mfc1 %0, %1" : "=r" (bitsStart) : "f" (1.0f - u * (4.0f - u * 3.0f)));
        int bitsEnd;
        asm("mfc1 %0, %1" : "=r" (bitsEnd) : "f" (u * (u * 3.0f + -2.0f)));
        asm("qmtc2.ni %0, vf6" : : "r" (between));
        asm("qmtc2.ni %0, vf2" : : "r" (bitsScale));
        asm("lqc2 vf5, %0" : : "m" (gBetweenVec));
        asm("lqc2 vf7, %0" : : "m" (wStart));
        asm("lqc2 vf8, %0" : : "m" (wEnd));
        asm("qmtc2.ni %0, vf3" : : "r" (bitsEnd));
        asm("qmtc2.ni %0, vf1" : : "r" (bitsStart));
        asm("vmulax.xyzw ACC, vf6, vf5x");
        asm("vmaddax.xyzw ACC, vf7, vf1x");
        asm("vmaddx.xyzw vf4, vf8, vf3x");
        asm("vmulx.xyzw vf2, vf4, vf2x");
        asm("sqc2 vf2, 0(%0)" : : "r" (pwOut) : "memory");
    }
}
