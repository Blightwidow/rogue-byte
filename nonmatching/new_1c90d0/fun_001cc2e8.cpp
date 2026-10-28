#include "sly2.h"
struct M4 { QW row[4]; };
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);
struct Aloobj { char pad0[0xC]; struct VT *vtable; };
struct VT { char pad[0xF8]; short delta; short index; M4 *(*fn)(void *); };
struct Carry {
    void *pjt;
    void **ppasega;
    float weight0;
    char pad0[0x1C - 0xC];
    float weight1;
    char pad1[0x30 - 0x20];
    void *pasegbl;
    char pad2[0x38 - 0x34];
    char *pxfBase;
    char pad3[0x40 - 0x3C];
    M4 matBase;
    char pad4[0x80 - 0x80];
    void *pactLook;
    Aloobj *pcrv;
    float sPath;
    Aloobj *ploTarget;
    int kind;
    char pad5[0xA4 - 0x94];
    int state;
};
struct Probe { void *pcarry; char pad[0xC]; QW posFlat; };
extern "C" {
QW PosLoWorld(void *);
void FindCrvClosestPointFromS(void *, QW, float, int, QW *, int, int, float *);
void InvertMatrix4Affine(M4 *, const M4 *);
QW ConvertAloPos(void *, void *, QW);
float Carry_SDistStartCurves(void *, float);
float Carry_SDistEndCurves(void *, float);
void MinimizeRange__FPFPvf_fPvffffPfT6(float (*)(void *, float), void *, float *, float *, float, float, float, float);
void func_001CC1F8(Carry *, QW, float *, int, float);
void func_001CC168(Carry *, QW, float *, int, float);
void ConvertXfMat(void *, void *, void *, void *);
QW DecomposeRotateMatrixEuler(void *);
void func_0012D108(void *, QW);
void SeekAsega(void *, int, float, float);
void ReblendAsegbl(void *);
void SetStepRadTargetDir(void *, QW);
void FixStepAngularVelocity__FP4STEP(void *);
}
static inline M4 *GetMat(Aloobj *obj)
{
    VT *vt = obj->vtable;
    return vt->fn((char *)obj + vt->delta);
}
static inline MATRIX4 Inv(const MATRIX4 &m)
{
    MATRIX4 result;
    InvertMatrix4Affine((M4 *)&result, (const M4 *)&m);
    return result;
}
extern "C" void func_001CC2E8(Carry *carry)
{
    if (carry->state == -1)
        return;
    QW posTarget;
    QW rot[3];
    switch (carry->kind) {
    case 1:
        posTarget = PosLoWorld(carry->ploTarget);
        break;
    case 0: {
        Aloobj *crv = carry->pcrv;
        QW posJt = PosLoWorld(carry->pjt);
        FindCrvClosestPointFromS(crv, posJt, carry->sPath, 0, &posTarget, 0, 0, &carry->sPath);
        break;
    }
    case 2: {
        MATRIX4 rel;
        rel = *(MATRIX4 *)GetMat(carry->ploTarget) * Inv(*(MATRIX4 *)&carry->matBase);
        QW *rows = (QW *)&rel;
        rot[0] = rows[0];
        rot[1] = rows[1];
        rot[2] = rows[2];
        posTarget = rows[3];
        break;
    }
    }
    Probe probe;
    QW flat;
    float u, sdist, gblend;
    QW posLocal = ConvertAloPos(0, carry->pjt, posTarget);
    probe.pcarry = carry;
    QW chain;
    float root;
    asm("qmtc2.ni %1, vf1\n\tvmul.xy vf2, vf1, vf1\n\tvaddy.x vf2, vf2, vf2y" : "=r" (chain) : "r" (posLocal));
    asm("sqc2 vf1, %0" : "=m" (flat) : "r" (chain));
    asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tqmfc2.ni %0, vf2" : "=r" (root) : "r" (chain));
    ((int *)&flat)[1] = 0;
    *(int *)&flat = (int)root;
    probe.posFlat = ConvertAloPos(carry->pjt, 0, flat);
    if (carry->kind == 2) {
        MinimizeRange__FPFPvf_fPvffffPfT6(Carry_SDistEndCurves, &probe, &u, &sdist, 0.5f, 0.1f, 0.0f, 1.0f);
        func_001CC1F8(carry, probe.posFlat, &gblend, 0, u);
        QW inParent[4];
        ConvertXfMat(inParent, 0, *(void **)(carry->pxfBase + 0xA0), rot);
        QW rot2[3];
        rot2[0] = inParent[0];
        rot2[1] = inParent[1];
        rot2[2] = inParent[2];
        QW euler = DecomposeRotateMatrixEuler(rot2);
        func_0012D108(carry->pactLook, euler);
    } else {
        MinimizeRange__FPFPvf_fPvffffPfT6(Carry_SDistStartCurves, &probe, &u, &sdist, 0.5f, 0.1f, 0.0f, 1.0f);
        func_001CC168(carry, probe.posFlat, &gblend, 0, u);
    }
    SeekAsega(*carry->ppasega, 0, u * *(float *)((char *)carry->pasegbl + 0x74), 0.0f);
    float gb = gblend;
    carry->weight1 = gb;
    carry->weight0 = 1.0f - gb;
    ReblendAsegbl(carry->pasegbl);
    QW posJt = PosLoWorld(carry->pjt);
    QW dpos;
    asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2\n\tvsub.xyzw vf1, vf1, vf2\n\tqmfc2.ni %0, vf1" : "=r" (dpos) : "m" (posTarget), "r" (posJt));
    SetStepRadTargetDir(carry->pjt, dpos);
    FixStepAngularVelocity__FP4STEP(carry->pjt);
}
