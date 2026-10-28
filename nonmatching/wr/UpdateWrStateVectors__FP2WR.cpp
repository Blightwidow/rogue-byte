#include "sly2.h"
struct WR { char pad0[0x54]; int cwre; };
struct Rows { QW row[4]; };
extern "C" {
Rows *InvertMatrix4Affine(Rows *, Rows *);
void CopyAb__FPvT0Ui(void *, void *, unsigned int);
QW ConvertAloPos(void *, void *, QW);
float RadNormalize__Ff(float);
void CalculateSinCos__FfPfT1(float, float *, float *);
Rows *__ml__FRC7MATRIX4T0(Rows *, const Rows *, const Rows *);
extern QW g_2a2dd0;
extern QW g_2a2da0;
extern QW g_2a2db0;
extern QW g_2a2dc0;
}
struct Locals {
    Rows env;                // 0x00
    float base, slope, quad, pad4c;
    float wmin, wmax, pad58, pad5c;
    Rows w60;                // 0x60
    QW a0;                   // 0xA0
    Rows inv;                // 0xB0
    QW aposBase[256];        // 0xF0
    float aWeight[256];      // 0x10F0
    float gSin, gCos;        // 0x14F0
};
void UpdateWrStateVectors(WR *pwr)
{
    Locals L;
    QW posBend;
    QW posBendWorld;
    char *pwrbg = *(char **)((char *)pwr + 0x8F0);
    while (pwrbg) {
        if (*(int *)(pwrbg + 0x30) == -1) {
            memset(&L.env, 0, 0x40);
            float *pf = (float *)&L.env;
            pf[0] = 1.0f; pf[5] = 1.0f; pf[10] = 1.0f; pf[15] = 1.0f;
            posBend = g_2a2dd0;
        } else {
            L.env.row[0] = *(QW *)(pwrbg + 0x50);
            L.env.row[1] = *(QW *)(pwrbg + 0x60);
            L.env.row[2] = *(QW *)(pwrbg + 0x70);
            L.env.row[3] = *(QW *)(pwrbg + 0x80);
            float *pg = (float *)pwrbg;
            L.wmin = pg[0x40 / 4] < pg[0x38 / 4] ? pg[0x40 / 4] : pg[0x38 / 4];
            L.wmax = pg[0x38 / 4] < pg[0x40 / 4] ? pg[0x40 / 4] : pg[0x38 / 4];
            L.slope = (pg[0x38 / 4] - pg[0x40 / 4]) / (pg[0x34 / 4] - pg[0x3C / 4]);
            L.quad = 0;
            L.base = pg[0x38 / 4] - L.slope * pg[0x34 / 4];
            switch (*(int *)(pwrbg + 0x30)) {
            case 4:
            case 5:
            case 6: {
                float mid = (*(float *)(pwrbg + 0x34) + *(float *)(pwrbg + 0x3C)) * 0.5f;
                QW *paxis = *(int *)(pwrbg + 0x30) == 5 ? &g_2a2db0 : (*(int *)(pwrbg + 0x30) == 4 ? &g_2a2da0 : &g_2a2dc0);
                int bits = *(int *)&mid;
                QW result;
                int token;
                asm("lqc2 vf2, %1" : "=r" (token) : "m" (*paxis));
                asm("qmtc2.ni %0, vf1" : "+r" (token) : "r" (bits));
                asm("vmulx.xyzw vf3, vf2, vf1x" : "+r" (token));
                asm("sqc2 vf1, %1" : "+r" (token), "=m" (L.w60.row[0]));
                asm("sqc2 vf3, %1" : "+r" (token), "=m" (posBend));
                break;
            }
            default:
                posBend = g_2a2dd0;
                break;
            }
            InvertMatrix4Affine(&L.inv, &L.env);
            int token;
            asm("lqc2 vf1, %1" : "=r" (token) : "m" (L.inv.row[0]));
            asm("lqc2 vf2, %1" : "+r" (token) : "m" (L.inv.row[1]));
            asm("lqc2 vf3, %1" : "+r" (token) : "m" (L.inv.row[2]));
            asm("lqc2 vf4, %1" : "+r" (token) : "m" (L.inv.row[3]));
            asm("lqc2 vf5, %1" : "+r" (token) : "m" (posBend));
            asm("vmulax.xyz ACC, vf1, vf5x\n\tvmadday.xyz ACC, vf2, vf5y\n\tvmaddaz.xyz ACC, vf3, vf5z\n\tvmaddw.xyz vf5, vf4, vf0w" : "+r" (token));
            asm("sqc2 vf1, %1" : "+r" (token), "=m" (L.w60.row[1]));
            asm("sqc2 vf5, %1" : "+r" (token), "=m" (posBend));
            asm("sqc2 vf2, %1" : "+r" (token), "=m" (L.w60.row[2]));
            asm("sqc2 vf3, %1" : "+r" (token), "=m" (L.w60.row[3]));
            asm("sqc2 vf4, %1" : "+r" (token), "=m" (L.a0));
            char *pdmat = *(char **)(*(char **)(pwrbg + 4) + 8);
            if (pdmat) {
                Rows *pproduct = __ml__FRC7MATRIX4T0(&L.inv, (Rows *)(pwrbg + 0x50), (Rows *)pdmat);
                L.env = *pproduct;
            }
        }
        char *pwrbsg = *(char **)(pwrbg + 0x90);
        while (pwrbsg) {
            int cvertex = *(int *)pwrbsg;
            CopyAb__FPvT0Ui(L.aposBase, *(void **)(pwrbsg + 4), cvertex << 4);
            QW *pend = L.aposBase + cvertex;
            float *pweight = L.aWeight;
            for (QW *ppos = L.aposBase; ppos < pend; ppos++, pweight++) {
                int token;
                asm("lqc2 vf5, %1" : "=r" (token) : "m" (*ppos));
                asm("lqc2 vf2, %1" : "+r" (token) : "m" (L.env.row[0]));
                asm("lqc2 vf4, %1" : "+r" (token) : "m" (L.env.row[1]));
                asm("lqc2 vf3, %1" : "+r" (token) : "m" (L.env.row[2]));
                asm("lqc2 vf1, %1" : "+r" (token) : "m" (L.env.row[3]));
                asm("vmulax.xyz ACC, vf2, vf5x\n\tvmadday.xyz ACC, vf4, vf5y\n\tvmaddaz.xyz ACC, vf3, vf5z\n\tvmaddw.xyz vf2, vf1, vf0w" : "+r" (token));
                asm("sqc2 vf2, %1" : "+r" (token), "=m" (L.w60.row[0]));
                float g;
                float *pw = (float *)&L.w60;
                switch (*(int *)(pwrbg + 0x30)) {
                case -1:
                default:
                    *pweight = 1.0f;
                    continue;
                case 1:
                    pw[2] = 0;
                    goto len;
                case 2:
                    pw[1] = 0;
                case 0:
                len:
                    int token;
                    asm("lqc2 vf1, %1" : "=r" (token) : "m" (L.w60.row[0]));
                    asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "+r" (token));
                    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "+r" (token));
                    {
                        int bits;
                        asm("qmfc2.ni %1, vf1" : "+r" (token), "=r" (bits));
                        asm("mtc1 %1, %0\n\tnop" : "=f" (g) : "r" (bits));
                    }
                    break;
                case 3:
                    pw[0] = 0;
                    goto len;
                case 4:
                    g = pw[0];
                    break;
                case 5:
                    g = pw[1];
                    break;
                case 6:
                    g = pw[2];
                    break;
                }
                float weight = L.base + g * (L.slope + g * L.quad);
                if (weight < L.wmin) weight = L.wmin;
                else if (L.wmax < weight) weight = L.wmax;
                *pweight = weight;
            }
            char *pglob2 = *(char **)(pwrbg + 4);
            char *pmat = *(char **)(pglob2 + 4);
            L.w60.row[0] = *(QW *)(pmat + 0x40);
            L.w60.row[1] = *(QW *)(pmat + 0x50);
            L.w60.row[2] = *(QW *)(pmat + 0x60);
            L.w60.row[3] = *(QW *)(pmat + 0x70);
            char *pdmat2 = *(char **)(*(char **)(pwrbg + 4) + 8);
            if (pdmat2) {
                Rows *pproduct2 = __ml__FRC7MATRIX4T0((Rows *)&L.a0, &L.w60, (Rows *)pdmat2);
                L.w60 = *pproduct2;
            }
            posBendWorld = ConvertAloPos(*(void **)pwrbg, 0, posBend);
            for (int iwre = 0; iwre < pwr->cwre; iwre++) {
                char *pwre = (char *)pwr + (iwre * 0xD0 + 0x60);
                float *pgState = *(float **)(pwrbsg + (*(int *)(pwre + 4) << 2) + 8);
                float *pweight2 = L.aWeight;
                for (QW *ppos2 = L.aposBase; ppos2 < pend; ppos2++, pweight2++, pgState += 4) {
                    int token;
                    asm("lqc2 vf5, %1" : "=r" (token) : "m" (*ppos2));
                    asm("lqc2 vf4, %1" : "+r" (token) : "m" (L.w60.row[0]));
                    asm("lqc2 vf3, %1" : "+r" (token) : "m" (L.w60.row[1]));
                    asm("lqc2 vf2, %1" : "+r" (token) : "m" (L.w60.row[2]));
                    asm("lqc2 vf1, %1" : "+r" (token) : "m" (L.w60.row[3]));
                    asm("vmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf1, vf1, vf0w" : "+r" (token));
                    int wrek = *(int *)pwre;
                    asm("vmove.xyzw vf4, vf1" : "+r" (token));
                    asm("sqc2 vf4, %1" : "+r" (token), "=m" (L.a0));
                    if (wrek == 0) {
                        asm("lqc2 vf2, %1" : "+r" (token) : "m" (*(QW *)(pwre + 0x10)));
                        asm("vmul.xyz vf1, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z" : "+r" (token));
                        float rgDot = *(float *)(pwre + 0x64);
                        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf2, Q" : "+r" (token));
                        int is = *(int *)(pwre + 0x60);
                        float rate = rgDot * 6.2831855f;
                        asm("vmul.xyz vf1, vf4, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "+r" (token));
                        int bits;
                        asm("qmfc2.ni %1, vf1" : "+r" (token), "=r" (bits));
                        float along;
                        asm("mtc1 %1, %0" : "=f" (along) : "r" (bits));
                        float rad = RadNormalize__Ff(along * rate);
                        CalculateSinCos__FfPfT1(rad, &L.gSin, &L.gCos);
                        pgState[is] = L.gCos * *pweight2;
                        pgState[is + 1] = L.gSin * *pweight2;
                    } else if (wrek == 1) {
                        asm("lqc2 vf2, %1" : "+r" (token) : "m" (posBendWorld));
                        asm("vsub.xyzw vf1, vf1, vf2" : "+r" (token));
                        asm("sqc2 vf1, %1" : "+r" (token), "=m" (L.inv.row[0]));
                        float *pd = (float *)&L.inv.row[0];
                        pgState[0] = *pweight2 * pd[0];
                        pgState[1] = *pweight2 * pd[1];
                        pgState[3] = 1.0f;
                        pgState[2] = *pweight2 * pd[2];
                    }
                }
            }
            pwrbsg = *(char **)(pwrbsg + 0x18);
        }
        pwrbg = *(char **)(pwrbg + 0xA0);
    }
    *(int *)((char *)pwr + 0x8FC) = 0;
}
