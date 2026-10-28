#include "sly2.h"
struct WR { char pad0[0x50]; float tLast; int cwre; };
struct ONZ;
extern "C" void UpdateLo(WR *);
void UpdateWrStateVectors(WR *);
float RadNormalize(float);
void CalculateSinCos(float, float *, float *);
float GFromOnz(ONZ *);
struct Rows { QW row[3]; };
extern "C" void LoadRotateMatrixRad(Rows *, QW, float);
extern float g_2dded0;
void UpdateWrMatrixes(WR *pwr)
{
    UpdateLo(pwr);
    if (g_2dded0 == pwr->tLast) return;
    if (*(int *)((char *)pwr + 0x8FC) != 0)
        UpdateWrStateVectors(pwr);
    struct Locals { Rows copy; Rows junkRows; QW junkQ; Rows mat; float sin; int cos; } L;
    int index = 0;
    while (index < pwr->cwre) {
        char *pwre = (char *)pwr + (index * 0xD0 + 0x60);
        int imat = *(int *)(pwre + 4);
        char *pmatDpos = (char *)pwr + (imat * 0x40 + 0x6F0);
        char *pmatDuv = (char *)pwr + (imat * 0x40 + 0x7F0);
        int kind = *(int *)pwre;
        switch (kind) {
        case 0: {
            float rad = RadNormalize((g_2dded0 * *(float *)(pwre + 0x68) + *(float *)(pwre + 0x6C)) * 6.2831855f);
            CalculateSinCos(rad, &L.sin, (float *)&L.cos);
            int t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
            asm("qmtc2.ni %1, vf3" : "=r" (t0) : "r" (L.cos), "f" (L.sin));
            asm("lqc2 vf2, %1" : "=r" (t1) : "m" (*(QW *)(pwre + 0x40)), "r" (t0));
            asm("lqc2 vf1, %1" : "=r" (t2) : "m" (*(QW *)(pwre + 0x20)), "r" (t1));
            asm("qmtc2.ni %1, vf4" : "=r" (t3) : "r" (L.sin), "r" (t2));
            int is = *(int *)(pwre + 0x60);
            float nsin = -L.sin;
            asm("vmulax.xyzw ACC, vf1, vf3x\n\tvmaddx.xyzw vf1, vf2, vf4x" : "=r" (t4) : "r" (t3));
            asm("sqc2 vf1, %1" : "=r" (t5), "=m" (L.copy.row[0]) : "r" (t4));
            asm("qmtc2.ni %1, vf5" : "=r" (t6) : "r" (nsin), "r" (t5));
            float *pRowA = (float *)(pmatDpos + is * 16);
            float *pRowB = (float *)(pmatDpos + (is + 1) * 16);
            float *pUvA = (float *)(pmatDuv + is * 16);
            float *pUvB = (float *)(pmatDuv + (is + 1) * 16);
            { float v2 = ((float *)&L.copy)[2]; float v0 = ((float *)&L.copy)[0]; float v1 = ((float *)&L.copy)[1]; pRowA[0] = v0; pRowA[1] = v1; pRowA[2] = v2; }
            asm("sqc2 vf3, %1" : "=r" (t7), "=m" (L.copy.row[2]) : "r" (t6));
            asm("lqc2 vf1, %1" : "=r" (t8) : "m" (*(QW *)(pwre + 0x40)), "r" (t7));
            asm("lqc2 vf2, %1" : "=r" (t9) : "m" (*(QW *)(pwre + 0x20)), "r" (t8));
            asm("vmulax.xyzw ACC, vf2, vf5x\n\tvmaddx.xyzw vf2, vf1, vf3x" : "=r" (t10) : "r" (t9));
            asm("sqc2 vf4, %1" : "=r" (t11), "=m" (L.copy.row[2]) : "r" (t10));
            asm("sqc2 vf2, %1" : "=r" (t12), "=m" (L.copy.row[0]) : "r" (t11));
            asm("sqc2 vf3, %1" : "=r" (t13), "=m" (L.copy.row[2]) : "r" (t12));
            { float v0 = ((float *)&L.copy)[0]; float v1 = ((float *)&L.copy)[1]; float v2 = ((float *)&L.copy)[2]; pRowB[0] = v0; pRowB[1] = v1; pRowB[2] = v2; }
            asm("sqc2 vf4, %1" : "=r" (t14), "=m" (L.copy.row[2]) : "r" (t13));
            asm("lqc2 vf2, %1" : "=r" (t15) : "m" (*(QW *)(pwre + 0x50)), "r" (t14));
            int u0, u1, u2, u3, u4, u5, u6, u7;
            asm("lqc2 vf1, %1" : "=r" (u0) : "m" (*(QW *)(pwre + 0x30)), "r" (t15));
            asm("vmulax.xyzw ACC, vf1, vf3x\n\tvmaddx.xyzw vf1, vf2, vf4x" : "=r" (u1) : "r" (u0));
            asm("sqc2 vf1, %1" : "=r" (u2), "=m" (L.copy.row[1]) : "r" (u1));
            { float v0 = ((float *)&L.copy)[4]; float v1 = ((float *)&L.copy)[5]; pUvA[0] = v0; pUvA[1] = v1; }
            asm("lqc2 vf2, %1" : "=r" (u3) : "m" (*(QW *)(pwre + 0x30)), "r" (u2));
            asm("sqc2 vf3, %1" : "=r" (u4), "=m" (L.copy.row[2]) : "r" (u3));
            asm("lqc2 vf1, %1" : "=r" (u5) : "m" (*(QW *)(pwre + 0x50)), "r" (u4));
            asm("vmulax.xyzw ACC, vf2, vf5x\n\tvmaddx.xyzw vf5, vf1, vf3x" : "=r" (u6) : "r" (u5));
            asm("sqc2 vf5, %1" : "=r" (u7), "=m" (L.copy.row[1]) : "r" (u6));
            { float v0 = ((float *)&L.copy)[4]; float v1 = ((float *)&L.copy)[5]; pUvB[0] = v0; pUvB[1] = v1; }
            break;
        }
        case 1: {
            float radBend = GFromOnz((ONZ *)(pwre + 0x30));
            float radSwivel = GFromOnz((ONZ *)(pwre + 0x80));
            QW axis;
            int b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14;
            asm("lqc2 vf2, %1" : "=r" (b0) : "m" (*(QW *)(pwre + 0x20)));
            asm("vmul.xyz vf1, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z" : "=r" (b1) : "r" (b0));
            asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf3, vf2, Q" : "=r" (b2) : "r" (b1));
            asm("qmfc2.ni %0, vf3" : "=r" (axis) : "r" (b2));
            LoadRotateMatrixRad(&L.mat, axis, radSwivel);
            asm("lqc2 vf2, %1" : "=r" (b3) : "m" (*(QW *)(pwre + 0x10)));
            asm("vmul.xyz vf1, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z" : "=r" (b4) : "r" (b3));
            asm("lqc2 vf4, %1" : "=r" (b5) : "m" (L.mat.row[0]), "r" (b4));
            asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (b6) : "r" (b5));
            asm("lqc2 vf5, %1" : "=r" (b7) : "m" (L.mat.row[1]), "r" (b6));
            asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf2, Q" : "=r" (b8) : "r" (b7));
            asm("lqc2 vf6, %1" : "=r" (b9) : "m" (L.mat.row[2]), "r" (b8));
            asm("vmulax.xyz ACC, vf4, vf1x\n\tvmadday.xyz ACC, vf5, vf1y\n\tvmaddz.xyz vf1, vf6, vf1z" : "=r" (b10) : "r" (b9));
            asm("vmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z" : "=r" (b11) : "r" (b10));
            asm("sqc2 vf4, %1" : "=r" (b12), "=m" (L.junkRows.row[0]) : "r" (b11));
            asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "=r" (b13) : "r" (b12));
            asm("sqc2 vf5, %1" : "=r" (b14), "=m" (L.junkRows.row[1]) : "r" (b13));
            int b15, b16, b17;
            asm("vdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf3, vf1, Q" : "=r" (b15) : "r" (b14));
            asm("sqc2 vf6, %1" : "=r" (b16), "=m" (L.junkRows.row[2]) : "r" (b15));
            asm("qmfc2.ni %0, vf3" : "=r" (axis) : "r" (b16));
            QW junk;
            asm("sqc2 vf1, %1" : "=r" (b17), "=m" (L.junkQ) : "r" (b16));
            LoadRotateMatrixRad(&L.mat, axis, radBend);
            L.copy = L.mat;
            float *pgDelta = (float *)pmatDpos;
            float *pf = (float *)&L.copy;
            pgDelta[0] = pf[0] - 1.0f;
            pgDelta[1] = pf[1];
            pgDelta[2] = pf[2];
            pgDelta[4] = pf[4];
            pgDelta[5] = pf[5] - 1.0f;
            pgDelta[6] = pf[6];
            pgDelta[8] = pf[8];
            pgDelta[9] = pf[9];
            pgDelta[10] = pf[10] - 1.0f;
            break;
        }
        }
        index = index + 1;
    }
    pwr->tLast = g_2dded0;
}
