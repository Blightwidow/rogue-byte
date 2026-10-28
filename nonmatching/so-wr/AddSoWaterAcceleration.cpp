#include "sly2.h"
struct SO;
struct VT {
    char pad[0x108];
    short delta0;
    short index0;
    QW (*fnGetVel)(void *);
    short delta1;
    short index1;
    QW (*fnGetAng)(void *);
};
struct SOBASE { char pad[0x174]; };
struct REFBASE { int ptr; };
struct SOD : SOBASE, REFBASE {};
struct Frame {
    QW posSurface;
    QW normal;
    QW curLin;
    QW curAng;
    QW dvNormal;
    QW dvTangent;
    float clq[4];
    QW dwNormal;
    QW dwTangent;
    QW junk;
    QW radTilt;
    QW dv;
    QW wSo;
};
extern "C" {
float UGetWaterSubmerged(void *, void *, void *, void *);
int FFloatsNear__Ffff(float, float, float);
QW ApplyConstrLocal(void *, void *, QW);
void AddSoAcceleration(void *, QW);
int FXfKindDynamic(int);
void AccelSoTowardPosSpring(void *, QW, int, QW, void *);
void AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(void *, void *, int, QW, void *);
float SProjectVector__FP6VECTORT0(QW, QW, void *, void *);
QW PosLoWorld(void *);
void *PmatLoWorld(void *);
void TiltMatUpright__FP7MATRIX3N20(void *, void *, int);
void DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(void *, void *, void *);
void AddSoAngularAcceleration(void *, QW);
void WakeSoWater__FP2SOP5WATERfP6VECTORT3ff(void *, void *, float, QW, QW, float, float);
int FIsBasicDerivedFrom(void *, int);
void StopAmb(int, float);
void VirtualRefPtr_Assign(void *, int);
void LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4(void *, QW, void *, void *);
extern QW g_2a2dd0;
extern QW RO_002A2D00;
extern float D_002C4470[3];
extern float D_002C4480[3];
extern float g_2dded4;
}
void AddSoWaterAcceleration(char *pso, char *pwater)
{
    Frame f;
    float uSubmerged = UGetWaterSubmerged(pwater, pso, &f.posSurface, &f.normal);
    if (uSubmerged < 0.0001f)
        return;
    QW grav = *(QW *)(*(char **)(pso + 0xE8) + 0x80);
    QW zero = g_2a2dd0;
    int noGravity = 0;
    float xZero, xGrav;
    asm("mtc1 %1, %0" : "=f"(xZero) : "r"(zero));
    asm("mtc1 %1, %0" : "=f"(xGrav) : "r"(grav));
    if (FFloatsNear__Ffff(xZero, xGrav, 0.0001f)) {
        int yZero, yGrav;
        asm("prot3w %0, %1" : "=r"(yZero) : "r"(zero));
        asm("prot3w %0, %1" : "=r"(yGrav) : "r"(grav));
        if (FFloatsNear__Ffff(*(float *)&yZero, *(float *)&yGrav, 0.0001f)) {
            int zZero, zGrav;
            asm("pextuw %0, $0, %1" : "=r"(zZero) : "r"(zero));
            asm("pextuw %0, $0, %1" : "=r"(zGrav) : "r"(grav));
            noGravity = FFloatsNear__Ffff(*(float *)&zZero, *(float *)&zGrav, 0.0001f) != 0;
        }
    }
    float gBuoyancy;
    if (noGravity)
        gBuoyancy = 0.0f;
    else
        gBuoyancy = *(float *)(*(char **)(pso + 0xE8) + 0xD4) * *(float *)(*(char **)(pwater + 0xE8) + 0xD4);
    float gViscosity = *(float *)(*(char **)(pso + 0xE8) + 0xD8) * *(float *)(*(char **)(pwater + 0xE8) + 0xD8);
    if (gBuoyancy != 0.0f) {
        float scale = -gBuoyancy * uSubmerged;
        QW dv;
        asm("mfc1 $3, %2\n\tqmtc2.ni $3, vf2\n\tsqc2 vf2, %1\n\tlqc2 vf1, %3\n\tvmulx.xyzw vf3, vf1, vf2x\n\tqmfc2.ni %0, vf3" : "=r"(dv), "=m"(f.curLin) : "f"(scale), "m"(*(QW *)(*(char **)(pso + 0xE8) + 0x80)) : "$3");
        AddSoAcceleration(pso, ApplyConstrLocal(*(char **)(pso + 0xE8) + 0xB0, *(void **)(pso + 0x60), dv));
    }
    if (gViscosity != 0.0f) {
        LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4(pwater, PosLoWorld(pso), &f.curLin, &f.curAng);
        VT *vt = *(VT **)(pso + 0xC);
        QW vSo = vt->fnGetVel(pso + vt->delta0);
        QW dvec;
        asm("sq %0, %1\n\tqmtc2.ni %0, vf2\n\tlqc2 vf1, %2\n\tvsub.xyzw vf2, vf1, vf2" : : "r"(vSo), "m"(f.dv), "m"(f.curLin));
        asm("qmfc2.ni %0, vf2" : "=r"(dvec));
        float sdvNormal = SProjectVector__FP6VECTORT0(dvec, f.normal, &f.dvNormal, &f.dvTangent);
        float uNormalScale;
        if (uSubmerged == 1.0f || 0.0f < sdvNormal)
            uNormalScale = 1.0f;
        else
            uNormalScale = uSubmerged * 0.5f + 0.5f;
        if (FXfKindDynamic(*(short *)(*(char **)(pso + 0x58) + 0x98))) {
            for (int index = 0; index < 3; index++)
                f.clq[index] = D_002C4470[index] * uNormalScale * gViscosity;
            QW sum;
            asm("lqc2 vf1, %1\n\tlqc2 vf3, %2\n\tvadd.xyzw vf3, vf3, vf1\n\tqmfc2.ni %0, vf3" : "=r"(sum) : "m"(f.dvNormal), "m"(f.dv));
            AccelSoTowardPosSpring(pso, g_2a2dd0, 0, sum, f.clq);
            for (int index = 0; index < 3; index++)
                f.clq[index] = D_002C4470[index] * uSubmerged * gViscosity;
            asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyzw vf2, vf2, vf1\n\tqmfc2.ni %0, vf2" : "=r"(sum) : "m"(f.dvTangent), "m"(f.dv));
            AccelSoTowardPosSpring(pso, g_2a2dd0, 0, sum, f.clq);
        }
        if (FXfKindDynamic(*(short *)(*(char **)(pso + 0x5C) + 0x98))) {
            VT *vt2 = *(VT **)(pso + 0xC);
            QW wSo = vt2->fnGetAng(pso + vt2->delta1);
            f.wSo = wSo;
            float minusOne = -1.0f;
            QW dw;
            asm("mfc1 $3, %2\n\tqmtc2.ni $3, vf1\n\tlqc2 vf2, %3\n\tvmulx.xyzw vf2, vf2, vf1x\n\tsqc2 vf1, %1\n\tqmfc2.ni %0, vf2" : "=r"(dw), "=m"(f.junk) : "f"(minusOne), "m"(f.wSo) : "$3");
            SProjectVector__FP6VECTORT0(dw, f.normal, &f.dwNormal, &f.dwTangent);
            for (int index = 0; index < 3; index++)
                f.clq[index] = D_002C4480[index] * uSubmerged * gViscosity;
            QW sum;
            asm("lqc2 vf1, %1\n\tlqc2 vf3, %2\n\tvadd.xyzw vf3, vf3, vf1\n\tqmfc2.ni %0, vf3" : "=r"(sum) : "m"(f.dwNormal), "m"(f.wSo));
            AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(pso, &RO_002A2D00, 0, sum, f.clq);
            for (int index = 0; index < 3; index++)
                f.clq[index] = D_002C4480[index] * gViscosity;
            asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyzw vf2, vf2, vf1\n\tqmfc2.ni %0, vf2" : "=r"(sum) : "m"(f.dwTangent), "m"(f.wSo));
            AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(pso, &RO_002A2D00, 0, sum, f.clq);
        }
    } else {
        ((float *)&f.curLin)[0] = 0.0f;
        ((float *)&f.curLin)[2] = 0.0f;
        ((float *)&f.curLin)[1] = 0.0f;
    }
    if (gBuoyancy != 0.0f) {
        TiltMatUpright__FP7MATRIX3N20(PmatLoWorld(pso), &f.curAng, 0);
        float radTilt;
        DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&f.curAng, &f.radTilt, f.clq);
        float amount = *(float *)&f.radTilt * (gBuoyancy * 3.0f) * uSubmerged;
        QW torque;
        asm("mfc1 $3, %2\n\tqmtc2.ni $3, vf1\n\tlqc2 vf2, %3\n\tvmulx.xyzw vf3, vf2, vf1x\n\tsqc2 vf1, %1\n\tqmfc2.ni %0, vf3" : "=r"(torque), "=m"(f.curAng) : "f"(amount), "m"(f.clq[0]) : "$3");
        AddSoAngularAcceleration(pso, torque);
    }
    if (0.0f < uSubmerged && uSubmerged < 1.0f && 0.9f < ((float *)&f.normal)[2]) {
        float *oxa = *(float **)(pso + 0xEC);
        float sRadius = ((oxa[4] - oxa[0]) + (oxa[5] - oxa[1])) * 0.25f;
        WakeSoWater__FP2SOP5WATERfP6VECTORT3ff(pso, pwater, g_2dded4, f.curLin, f.posSurface, 0.1f, sRadius);
    } else if (FIsBasicDerivedFrom(pso, 0x32)) {
        REFBASE *pref = (SOD *)pso;
        if (pref) {
            if (pref->ptr) {
                StopAmb(pref->ptr, 0.0f);
                VirtualRefPtr_Assign(pref, 0);
            }
        }
    }
}
