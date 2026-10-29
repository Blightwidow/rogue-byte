#include "sly2.h"
struct CLQ { float g0, g1, g2, pad; };
struct LM { float gMin, gMax; };
struct TN {
    char pad0[0x10C];
    void *pcrv;
    char pad1[0x120 - 0x110];
    int fCylinder;
    char pad2[0x12C - 0x124];
    int fFakeCylinder;
    char pad3[0x150 - 0x130];
    QW posFake;
    float sRadFake;
};
struct Rows3 { QW row[3]; };
struct Frame {
    QW dposCam;
    QW vecTangent;
    QW posBase;
    Rows3 junk;
    QW dposWorld;
    Rows3 matFrame;
};
extern "C" {
QW SetVectorCylind__FP6VECTORfff(float, float, float);
void GetPathPosFromS(float, void *, void *, void *);
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(void *, QW, QW);
QW ConvertAloPos(void *, void *, QW);
float fmodf(float, float);
extern QW g_2a2dc0;
}
void CalculateTnPos__FP2TNP6VECTORffP3CLQP2LM4FTNDT1(TN *ptn, float *pdposCrv, float sBase, float dsOffset, CLQ *aclq, LM *alm, int ftnd, QW *pposOther)
{
    Frame f;
    for (int icam = 0; icam < 3; icam++) {
        float gIn = pdposCrv[icam];
        float gMin = alm[icam].gMin;
        float gOut = aclq[icam].g0 + gIn * (aclq[icam].g1 + gIn * aclq[icam].g2);
        float gMax = alm[icam].gMax;
        if (gOut < gMin)
            gOut = gMin;
        else if (gMax < gOut)
            gOut = gMax;
        ((float *)&f.dposCam)[icam] = gOut;
    }
    if (ftnd == 2)
        ((float *)&f.dposCam)[0] = -((float *)&f.dposCam)[0];
    if (ptn->fCylinder != 0)
        f.dposCam = SetVectorCylind__FP6VECTORfff(((float *)&f.dposCam)[0], ((float *)&f.dposCam)[1], ((float *)&f.dposCam)[2]);
    QW up;
    QW tangent;
    if (ptn->pcrv != 0) {
        float sCam = (ftnd != 1) ? sBase - dsOffset : sBase + dsOffset;
        GetPathPosFromS(sCam, ptn->pcrv, &f.posBase, &f.vecTangent);
        tangent = f.vecTangent;
        up = g_2a2dc0;
    } else if (ptn->fFakeCylinder != 0) {
        float limit = ptn->sRadFake * 6.2831855f;
        float sCam;
        if (ftnd != 1)
            sCam = sBase - dsOffset;
        else
            sCam = sBase + dsOffset;
        sCam = fmodf(sCam, limit);
        QW radial = SetVectorCylind__FP6VECTORfff(sCam / ptn->sRadFake, ptn->sRadFake, 0.0f);
        asm("qmtc2.ni %4, vf3\n\tlqc2 vf4, %5\n\tlqc2 vf5, %6\n\tvadd.xyzw vf4, vf3, vf4\n\tvopmula.xyz ACC, vf5, vf3\n\tvopmsub.xyz vf1, vf3, vf5\n\tsqc2 vf3, %2\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf6, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf6, vf2z\n\tsqc2 vf4, %2\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tqmfc2.ni %0, vf5\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q\n\tqmfc2.ni %1, vf2\n\tsqc2 vf2, %3" : "=r"(up), "=r"(tangent), "=m"(f.posBase), "=m"(f.vecTangent) : "r"(radial), "m"(ptn->posFake), "m"(g_2a2dc0));
    } else {
        goto third;
    }
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&f.matFrame, tangent, up);
    asm("lqc2 vf2, %4\n\tlqc2 vf3, %5\n\tlqc2 vf4, %6\n\tlqc2 vf1, %7\n\tvmulax.xyz ACC, vf2, vf1x\n\tvmadday.xyz ACC, vf3, vf1y\n\tvmaddz.xyz vf1, vf4, vf1z\n\tsqc2 vf2, %0\n\tsqc2 vf1, %2\n\tsqc2 vf3, %1\n\tsqc2 vf4, %3" : "=m"(f.junk.row[0]), "=m"(f.junk.row[1]), "=m"(f.dposWorld), "=m"(f.junk.row[2]) : "m"(f.matFrame.row[0]), "m"(f.matFrame.row[1]), "m"(f.matFrame.row[2]), "m"(f.dposCam));
    goto done;
third:
    ((float *)&f.dposCam)[0] = ((float *)&f.dposCam)[0] + dsOffset;
    ((float *)&f.posBase)[2] = 0.0f;
    ((float *)&f.posBase)[1] = 0.0f;
    ((float *)&f.posBase)[0] = 0.0f;
    f.dposWorld = ConvertAloPos(ptn, 0, f.dposCam);
done:
    asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(*pposOther) : "m"(f.posBase), "m"(f.dposWorld));
}
