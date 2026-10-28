#include "sly2.h"
struct ROWS3 { QW row[3]; };
extern "C" QW PosLoWorld(void *);
extern "C" ROWS3 *PmatLoWorld(void *);
extern "C" char *func_001D2240(void *);
extern "C" void *func_001D22D0(void *);
extern "C" int FCheckLm__FP2LMf(void *, float);
extern "C" void SetVehicleAiState(void *, int);
extern "C" float acosf(float);
extern "C" float atan2f(float, float);
extern "C" void LoadRotateMatrixRad(ROWS3 *, float, QW);
extern "C" int ClsgClipEdgeToPathzone(void *, QW, QW, int, void *, int);
extern "C" void MeasureCrv(void *);
extern "C" void func_001D2420(void *);
extern "C" void func_001D2490(void *);
extern "C" void FFindPathzoneCrv(void *, QW, QW, void *);
extern "C" int FVehicleGunHasAmmo(void *);
extern "C" int func_00227C90(void *, QW);
extern "C" QW GetXfDofValue(void *, void *);
extern "C" float RadNormalize__Ff(float);
extern "C" void SetSmaGoal__FP3SMA3OID(void *, int);
extern "C" float GRandInRange(float, float);
extern "C" float g_2dded0, g_2c20e8, g_2c20ec, g_2c20f0, g_2c20f4, g_2c20f8;
extern "C" QW g_2a2dc0, g_2a2da0;

#define F32(v, off) (*(float *)((char *)(v) + (off)))
#define I32(v, off) (*(int *)((char *)(v) + (off)))
#define PTR(v, off) (*(char **)((char *)(v) + (off)))

struct FRAME {
    QW m0, m1, m2, m3;
    char alsg[0x180];
    QW posSelf, posTarget, vecToTarget, posGoal, vecOut;
};

static inline float Dist2(QW a, QW b)
{
    return 0;
}

extern "C" void UpdateVehicleAi(char *pv)
{
    FRAME f;
    float sDistance;
    f.posSelf = PosLoWorld(pv);
    f.posTarget = PosLoWorld(PTR(pv, 0x5A4));
    {
        int bits;
        asm("qmtc2.ni %0, vf1" : : "r"(f.posTarget));
        asm("lqc2 vf2, %0" : : "m"(f.posSelf));
        asm("vsub.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(f.vecToTarget));
        asm("lqc2 vf3, %0" : : "m"(f.vecToTarget));
        asm("vmul.xy vf1, vf1, vf3\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        asm("qmfc2.ni %0, vf1" : "=r"(bits));
        asm("mtc1 %1, %0" : "=f"(sDistance) : "r"(bits));
    }
    char *pgunActive = func_001D2240(pv);
    PTR(pv, 0x5BC) = pgunActive;
    if (pgunActive == 0)
        PTR(pv, 0x5B8) = (char *)func_001D22D0(pv);
    else
        PTR(pv, 0x5B8) = 0;
    int stateAi;
    do {
        stateAi = I32(pv, 0x188);
        switch (stateAi) {
        case 0:
            if (PTR(pv, 0x5BC) != 0) {
                if (FCheckLm__FP2LMf(PTR(pv, 0x5BC) + 0x88, sDistance) != 0)
                    SetVehicleAiState(pv, 1);
            } else if (PTR(pv, 0x5B8) != 0) {
                SetVehicleAiState(pv, 2);
            } else {
                SetVehicleAiState(pv, 3);
            }
            break;
        case 1:
            if (PTR(pv, 0x5BC) != 0) {
                if (FCheckLm__FP2LMf(PTR(pv, 0x5BC) + 0x90, sDistance) != 0)
                    break;
            }
            SetVehicleAiState(pv, 0);
            break;
        case 2:
            if (PTR(pv, 0x5B8) == 0)
                SetVehicleAiState(pv, 0);
            break;
        case 3:
            if (PTR(pv, 0x5BC) != 0 || PTR(pv, 0x5B8) != 0)
                SetVehicleAiState(pv, 0);
            break;
        }
    } while (stateAi != I32(pv, 0x188));
    switch (I32(pv, 0x188)) {
    case 0: {
        float standoff = F32(PTR(pv, 0x5BC), 0x7C);
        float far = standoff * g_2c20e8;
        far = far < sDistance ? sDistance : far;
        float radOffset = acosf(standoff / far);
        int bits;
        float length;
        asm("lqc2 vf1, %0" : : "m"(f.posSelf));
        asm("lqc2 vf2, %0" : : "m"(f.posTarget));
        asm("vsub.xyzw vf3, vf1, vf2");
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
        float eps = 0.0001f;
        int standoffBits = I32(PTR(pv, 0x5BC), 0x7C);
        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmtc2.ni %0, vf2" : : "r"(standoffBits));
        asm("qmfc2.ni %0, vf1" : "=r"(bits));
        asm("mtc1 %1, %0" : "=f"(length) : "r"(bits));
        asm("sqc2 vf2, %0" : "=m"(f.m0));
        if (length < eps) {
            asm("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
        } else {
            asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
        }
        asm("vmulx.xyzw vf3, vf1, vf2x\n\tsqc2 vf3, %0" : "=m"(f.vecOut));
        int mode = I32(PTR(pv, 0x5BC), 0x80);
        switch (mode) {
        case 0:
        case 1:
            f.posGoal = f.posTarget;
            break;
        case 2:
            LoadRotateMatrixRad((ROWS3 *)&f.m1, radOffset, g_2a2dc0);
            asm("lqc2 vf2, %0" : : "m"(f.m3));
            asm("lqc2 vf1, %0" : : "m"(f.m1));
            asm("lqc2 vf3, %0" : : "m"(f.m2));
            asm("lqc2 vf4, %0" : : "m"(f.vecOut));
            asm("vmulax.xyz ACC, vf1, vf4x\n\tvmadday.xyz ACC, vf3, vf4y\n\tvmaddz.xyz vf1, vf2, vf4z");
            asm("lqc2 vf2, %0" : : "m"(f.posTarget));
            asm("vadd.xyzw vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(f.posGoal));
            break;
        case 3:
            LoadRotateMatrixRad((ROWS3 *)&f.m0, -radOffset, g_2a2dc0);
            asm("lqc2 vf2, %0" : : "m"(f.m2));
            asm("lqc2 vf1, %0" : : "m"(f.m0));
            asm("lqc2 vf3, %0" : : "m"(f.m1));
            asm("lqc2 vf4, %0" : : "m"(f.vecOut));
            asm("vmulax.xyz ACC, vf1, vf4x\n\tvmadday.xyz ACC, vf3, vf4y\n\tvmaddz.xyz vf1, vf2, vf4z");
            asm("lqc2 vf2, %0" : : "m"(f.posTarget));
            asm("vadd.xyzw vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(f.posGoal));
            break;
        case 4:
            break;
        default:
            break;
        }
        char *pcrv = PTR(pv, 0x5AC);
        if (ClsgClipEdgeToPathzone(PTR(pv, 0x5A8), f.posSelf, f.posGoal, 4, &f.alsg[0], 2) == 1
            && *(float *)&f.alsg[0x40] == 0.0f && *(float *)&f.alsg[0x44] == 1.0f) {
            QW *apos = (QW *)PTR(PTR(pv, 0x5AC), 0xF4);
            apos[0] = f.posSelf;
            apos = (QW *)PTR(PTR(pv, 0x5AC), 0xF4);
            apos[1] = f.posGoal;
            I32(PTR(pv, 0x5AC), 0xE8) = 2;
            MeasureCrv(PTR(pv, 0x5AC));
            func_001D2420(pv);
        } else {
            char *crv = PTR(pv, 0x5AC);
            int cnode = I32(crv, 0xE8);
            int rebuild;
            if (cnode < 2) {
                rebuild = 1;
            } else {
                QW *apos = (QW *)PTR(crv, 0xF4);
                float distance;
                int dbits;
                asm("lqc2 vf2, %0" : : "m"(f.posTarget));
                asm("lqc2 vf1, %0" : : "m"(apos[cnode - 1]));
                float fifty = 50.0f;
                asm("vsub.xyzw vf1, vf1, vf2\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
                asm("qmfc2.ni %0, vf1" : "=r"(dbits));
                asm("mtc1 %1, %0" : "=f"(distance) : "r"(dbits));
                rebuild = fifty < distance;
            }
            if (rebuild) {
                FFindPathzoneCrv(PTR(pv, 0x5A8), f.posSelf, f.posTarget, crv);
                func_001D2420(pv);
            }
        }
        func_001D2490(pv);
        F32(pv, 0x54C) = F32(pv, 0x540);
    break; }
    case 1: {
        F32(pv, 0x544) = F32(pv, 0x540);
        I32(pv, 0x550) = 0;
        QW vecToTarget = f.vecToTarget;
        float vx, vy;
        asm("mtc1 %1, %0" : "=f"(vx) : "r"(vecToTarget));
        QW rot;
        asm("prot3w %0, %1" : "=r"(rot) : "r"(vecToTarget));
        asm("mtc1 %1, %0" : "=f"(vy) : "r"(rot));
        F32(pv, 0x54C) = atan2f(vy, vx);
        if (F32(pv, 0x5B4) < g_2dded0) {
            char *pgun = func_001D2240(pv);
            if (pgun != 0) {
                if (I32(pgun, 0x30) != 0) {
                    *(ROWS3 *)&f.m0 = *PmatLoWorld(PTR(pgun, 0x3C));
                    float radMuzzle = atan2f(((float *)&f.m0)[1], ((float *)&f.m0)[0]);
                    QW dof = GetXfDofValue(PTR(pgun, 0x30), PTR(pgun, 0x30));
                    float radError = RadNormalize__Ff(radMuzzle - F32(pv, 0x54C));
                    float absError = radError < 0 ? -radError : radError;
                    QW dofz;
                    asm("pextuw %0, $0, %1" : "=r"(dofz) : "r"(dof));
                    float dz;
                    asm("mtc1 %1, %0" : "=f"(dz) : "r"(dofz));
                    float diff = dz - F32(PTR(pgun, 0x34), 0x28);
                    if (!(absError < g_2c20ec)) break;
                    float absDiff = diff < 0 ? -diff : diff;
                    if (!(absDiff < g_2c20f0)) break;
                }
                SetSmaGoal__FP3SMA3OID(PTR(pgun, 0x20), 0x68);
                float tNow = g_2dded0;
                F32(pv, 0x5B4) = tNow + GRandInRange(1.0f, 1.5f);
            }
        }
    break; }
    case 2: {
        QW posChase = PosLoWorld(PTR(pv, 0x5B8));
        char *crv = PTR(pv, 0x5AC);
        int cnode = I32(crv, 0xE8);
        int rebuild;
        if (cnode < 2) {
            rebuild = 1;
        } else {
            QW *apos = (QW *)PTR(crv, 0xF4);
            float distance;
            int dbits;
            asm("qmtc2.ni %0, vf2" : : "r"(posChase));
            asm("lqc2 vf1, %0" : : "m"(apos[cnode - 1]));
            float fifty = 50.0f;
            asm("vsub.xyzw vf1, vf1, vf2\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
            asm("qmfc2.ni %0, vf1" : "=r"(dbits));
            asm("mtc1 %1, %0" : "=f"(distance) : "r"(dbits));
            rebuild = fifty < distance;
        }
        if (rebuild) {
            FFindPathzoneCrv(PTR(pv, 0x5A8), f.posSelf, posChase, crv);
            func_001D2420(pv);
        }
        func_001D2490(pv);
        F32(pv, 0x54C) = F32(pv, 0x540);
    break; }
    case 3: {
        QW vecToTarget = f.vecToTarget;
        float vx, vy;
        asm("mtc1 %1, %0" : "=f"(vx) : "r"(vecToTarget));
        QW rot;
        asm("prot3w %0, %1" : "=r"(rot) : "r"(vecToTarget));
        asm("mtc1 %1, %0" : "=f"(vy) : "r"(rot));
        float ang = atan2f(-vy, -vx);
        float speed = F32(pv, 0x51C) * 0.85f;
        float cur = F32(pv, 0x540);
        F32(pv, 0x544) = ang;
        F32(pv, 0x54C) = cur;
        F32(pv, 0x550) = speed;
    break; }
    }
    if (F32(pv, 0x5B4) < g_2dded0) {
        float fZero = 0.0f;
        for (int igun = 0; igun < I32(pv, 0x4F8); igun++) {
            char *pgun = PTR(pv, 0x4FC + igun * 4);
            if (FVehicleGunHasAmmo(pgun) == 0) continue;
            if (PTR(pgun, 0x84) != 0 && func_00227C90(PTR(pgun, 0x84), f.posTarget) == 0) continue;
            if (fZero < F32(pgun, 0x8C) && I32(pv, 0x188) != 1) continue;
            int fire = 1;
            if (I32(pgun, 0x30) != 0) {
                *(ROWS3 *)&f.m0 = *PmatLoWorld(PTR(pgun, 0x3C));
                float radMuzzle = atan2f(((float *)&f.m0)[1], ((float *)&f.m0)[0]);
                QW dof = GetXfDofValue(PTR(pgun, 0x30), PTR(pgun, 0x30));
                float radError = RadNormalize__Ff(radMuzzle - F32(pv, 0x54C));
                float absError = radError < 0 ? -radError : radError;
                QW dofz;
                asm("pextuw %0, $0, %1" : "=r"(dofz) : "r"(dof));
                float dz;
                asm("mtc1 %1, %0" : "=f"(dz) : "r"(dofz));
                float diff = dz - F32(PTR(pgun, 0x34), 0x28);
                if (g_2c20f4 < absError) continue;
                float absDiff = diff < 0 ? -diff : diff;
                if (g_2c20f8 < absDiff) continue;
            }
            SetSmaGoal__FP3SMA3OID(PTR(pgun, 0x20), 0x68);
            float tNow = g_2dded0;
            F32(pv, 0x5B4) = tNow + GRandInRange(F32(pgun, 0x98), F32(pgun, 0x9C));
        }
    }
}
