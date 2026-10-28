#include "sly2.h"
struct VGet { short delta; short index; QW (*fn)(void *); };
struct VSet { short delta; short index; void (*fn)(void *, QW); };
struct VT { char pad[0x108]; VGet get108; VGet get110; VSet set118; VSet set120; };
struct VEHICLE { char pad0[0xC]; VT *vptr; char pad1[0x560 - 0x10]; int hp; };
struct WKR { int pso; int unk4; int unk8; int kind; int dhp; };
extern "C" int FAbsorbSoWkr(VEHICLE *, WKR *);
extern "C" void UpdateVehicleHpBlot(VEHICLE *);
extern "C" void SetVehicleState(VEHICLE *, int);
extern "C" float GRandInRange(float, float);
extern "C" QW SetVectorCylind__FP6VECTORfff(float, float, float);
extern "C" QW PosLoWorld(void *);
extern "C" QW g_2a2dc0, g_2a2da0;
extern "C" float D_002C21D0[2], D_002C21D8[2], D_002C21E0[2], D_002C21E8[2], D_002C21F0[2], D_002C21F8[2], D_002C2200[2];

int FAbsorbVehicleWkr(VEHICLE *pv, WKR *pwkr)
{
    char buf[0x80] __attribute__((aligned(16)));
#define KLIN (*(QW *)(buf + 0x10))
#define KANG (*(QW *)(buf + 0x20))
#define JUNK0 (*(QW *)(buf + 0x0))
    if (FAbsorbSoWkr(pv, pwkr) == 0) return 0;
    int hpNew = pv->hp + pwkr->dhp;
    if (hpNew < 0) hpNew = 0;
    pv->hp = hpNew;
    UpdateVehicleHpBlot(pv);
    if (pv->hp == 0) SetVehicleState(pv, 3);
    QW zero;
    asm("vsub.xyzw vf1, vf0, vf0");
    asm("sqc2 vf1, %0" : "=m"(KLIN));
    asm("qmfc2.ni %0, vf1" : "=r"(zero));
    KANG = zero;
    switch (pwkr->kind) {
    case 0x100: {
        float radDir = GRandInRange(-3.14159274f, 3.14159274f);
        float sSide = GRandInRange(D_002C21D0[0], D_002C21D0[1]);
        float sLift = GRandInRange(D_002C21D8[0], D_002C21D8[1]);
        KLIN = SetVectorCylind__FP6VECTORfff(radDir, sSide, sLift);
        float gSpin = GRandInRange(D_002C21E0[0], D_002C21E0[1]);
        asm("lqc2 vf2, %0" : : "m"(KLIN));
        asm("lqc2 vf1, %0" : : "m"(g_2a2dc0));
        int gbits = *(int *)&gSpin;
        asm("qmtc2.ni %0, vf4" : : "r"(gbits));
        asm("vopmula.xyz ACC, vf1, vf2\n\tvopmsub.xyz vf3, vf2, vf1");
        float eps = 0.0001f;
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
        QW xaxis = g_2a2da0;
        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        int lbits;
        asm("qmfc2.ni %0, vf1" : "=r"(lbits));
        float len;
        asm("mtc1 %1, %0\n\tnop" : "=f"(len) : "r"(lbits));
        if (len < eps) {
            asm("sqc2 vf4, %0" : "=m"(JUNK0));
            asm("qmtc2.ni %0, vf1" : : "r"(xaxis));
        } else {
            asm("sqc2 vf4, %0" : "=m"(JUNK0));
            asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
        }
        asm("vmulx.xyzw vf2, vf1, vf4x");
        asm("sqc2 vf2, %0" : "=m"(KANG));
        break;
    }
    case 0x1000: {
        QW posPv = PosLoWorld(pv);
        asm("qmtc2.ni %0, vf3" : : "r"(posPv));
        asm("sqc2 vf3, %0" : "=m"(*(QW *)(buf + 0x70)));
        QW posSrc = PosLoWorld((void *)pwkr->pso);
        register QW *pz asm("$16") = &g_2a2dc0;
        asm("qmtc2.ni %0, vf4" : : "r"(posSrc));
        asm("lqc2 vf3, %0" : : "m"(*(QW *)(buf + 0x70)));
        asm("vsub.xyzw vf3, vf3, vf4");
        asm("lqc2 vf1, %0" : : "m"((*pz)));
        asm("vmul.xyz vf2, vf3, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z");
        float eps = 0.0001f;
        asm("vmulx.xyzw vf2, vf1, vf2x");
        QW xaxis = g_2a2da0;
        asm("vsub.xyzw vf3, vf3, vf2");
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        int lbits;
        asm("qmfc2.ni %0, vf1" : "=r"(lbits));
        float len;
        asm("mtc1 %1, %0\n\tnop" : "=f"(len) : "r"(lbits));
        if (len < eps) {
            *(QW *)(buf + 0x30) = xaxis;
        } else {
            asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q");
            asm("sqc2 vf2, %0" : "=m"(*(QW *)(buf + 0x30)));
        }
        float sPush = GRandInRange(D_002C21E8[0], D_002C21E8[1]);
        QW sPushBits;
        asm("mfc1 %0, %1" : "=r"(sPushBits) : "f"(sPush));
        *(QW *)(buf + 0x40) = sPushBits;
        float sLift = GRandInRange(D_002C21F0[0], D_002C21F0[1]);
        JUNK0 = *(QW *)(buf + 0x40);
        int sbits = *(int *)&sLift;
        asm("qmtc2.ni %0, vf2" : : "r"(sbits));
        asm("lqc2 vf1, %0" : : "m"((*pz)));
        asm("lqc2 vf4, %0" : : "m"(*(QW *)(buf + 0x30)));
        asm("lqc2 vf3, %0" : : "m"(*(QW *)(buf + 0x40)));
        asm("vmulax.xyzw ACC, vf4, vf3x\n\tvmaddx.xyzw vf3, vf1, vf2x");
        float gSpin = GRandInRange(D_002C21F8[0], D_002C21F8[1]);
        asm("sqc2 vf3, %0" : "=m"(KLIN));
        asm("sqc2 vf2, %0" : "=m"(JUNK0));
        QW gSpinBits;
        asm("mfc1 %0, %1" : "=r"(gSpinBits) : "f"(gSpin));
        *(QW *)(buf + 0x50) = gSpinBits;
        asm("lqc2 vf1, %0" : : "m"((*pz)));
        asm("lqc2 vf2, %0" : : "m"(*(QW *)(buf + 0x30)));
        float gTwistLo = D_002C2200[0];
        asm("vopmula.xyz ACC, vf1, vf2\n\tvopmsub.xyz vf2, vf2, vf1");
        asm("sqc2 vf2, %0" : "=m"(*(QW *)(buf + 0x60)));
        QW keep = *(QW *)(buf + 0x50);
        JUNK0 = keep;
        float gTwist = GRandInRange(gTwistLo, D_002C2200[1]);
        int tbits = *(int *)&gTwist;
        asm("qmtc2.ni %0, vf1" : : "r"(tbits));
        asm("lqc2 vf2, %0" : : "m"((*pz)));
        asm("lqc2 vf3, %0" : : "m"(*(QW *)(buf + 0x50)));
        asm("lqc2 vf4, %0" : : "m"(*(QW *)(buf + 0x60)));
        asm("vmulax.xyzw ACC, vf4, vf3x\n\tvmaddx.xyzw vf3, vf2, vf1x");
        asm("sqc2 vf1, %0" : "=m"(JUNK0));
        asm("sqc2 vf3, %0" : "=m"(KANG));
        break;
    }
    }
    VT *vt = pv->vptr;
    VSet *pset = &vt->set118;
    void *pself = (char *)pv + pset->delta;
    QW velLin = vt->get108.fn((char *)pv + vt->get108.delta);
    asm("lqc2 vf2, %0" : : "m"(KLIN));
    asm("qmtc2.ni %0, vf1" : : "r"(velLin));
    asm("vadd.xyzw vf1, vf1, vf2");
    QW sum1;
    asm("qmfc2.ni %0, vf1" : "=r"(sum1));
    pset->fn(pself, sum1);
    vt = pv->vptr;
    pset = &vt->set120;
    pself = (char *)pv + pset->delta;
    QW velAng = vt->get110.fn((char *)pv + vt->get110.delta);
    asm("qmtc2.ni %0, vf3" : : "r"(velAng));
    asm("lqc2 vf4, %0" : : "m"(KANG));
    asm("vadd.xyzw vf3, vf3, vf4");
    QW sum2;
    asm("qmfc2.ni %0, vf3" : "=r"(sum2));
    pset->fn(pself, sum2);
    return 1;
}
