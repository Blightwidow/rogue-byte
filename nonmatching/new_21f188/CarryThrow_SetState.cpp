#include "sly2.h"
struct VT {
    char pad0[0x40];
    short d40; short i40; void (*f40)(void *);
    short d48; short i48; void (*f48)(void *);
    char pad50[0x118 - 0x50];
    short d118; short i118; void (*f118)(void *, QW);
    char pad120[0x260 - 0x120];
    short d260; short i260; void (*f260)(void *, int);
    char pad268[0x278 - 0x268];
    short d278; short i278; void (*f278)(void *, int);
    char pad280[0x2D0 - 0x280];
    short d2D0; short i2D0; void (*f2D0)(void *);
};
struct Obj { char pad[0xC]; VT *vt; };
struct CT {
    char *pjt;
    int state;
    float tState;
    char *pref;
    char *pso;
    char pad14[0x40 - 0x14];
    float weight0;
    char pad44[0x4C - 0x44];
    float weight1;
    char pad50[0x58 - 0x50];
    void *asegHold;
    void *asegTurnRight;
    void *asegTurnLeft;
    void *asegPickup;
    char pad68[0x98 - 0x68];
    void *asegAim;
    void *asegAimTurnRight;
    void *asegAimTurnLeft;
    char padA4[0xBC - 0xA4];
    void *asegThrow;
    QW localAim;
    char padD0[0xE0 - 0xD0];
    QW posTarget;
    char padF0[0x128 - 0xF0];
    int fGoalActive;
    char *pdisplay;
    float tArc;
};
union FQ_2206C8 { QW q; float f; };
struct Frame { FQ_2206C8 u0; QW q10; FQ_2206C8 u20; QW q30; QW q40; };
extern "C" {
void Carry_Attach(void *, void *);
int FIsBasicDerivedFrom(void *, int);
void RecalcSwOxfFilterForObject(void *, void *);
float RadYawSo(void *);
void SetStepRadTarget(float, void *);
void SetStepRadTargetDir(void *, QW);
QW PosLoWorld(void *);
void func_00136530(void *, int);
void Carry_Detach(void *);
void FadeAloOut(float, void *);
void func_001A58D0(void *, int, int);
void ReblendAsegbl(void *);
QW ConvertAloPos(void *, void *, QW);
void CarryThrow_UpdateArc(void *, int);
void SpendJtGadgetPower(void *, int);
void RetractSmaRef(void *);
void ApplyAsegToHandle(void *, void *, int, void *, float, float);
extern void *g_2dd5bc;
extern float g_2dded0[];
extern char B_003DD490[];
extern QW g_2a2dd0;
extern QW g_2a2dc0;
extern QW g_2a2da0;
}
// float into lane 0 of a QW (mfc1)
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r"(r) : "f"(f)); return r; }
#define VCALL(obj, name, ...) (((Obj *)(obj))->vt->f##name((char *)(obj) + ((Obj *)(obj))->vt->d##name, ##__VA_ARGS__))
void CarryThrow_SetState(CT *c, int stateNew)
{
    Frame f;
    if (stateNew == c->state)
        return;
    switch (c->state) {
    case -1: {
        if (c->pso != g_2dd5bc)
            Carry_Attach(c->pjt + 0x900, c->pso);
        if (FIsBasicDerivedFrom(c->pso, 0x64))
            VCALL(c->pso, 260, 0);
        int *pjtInts = (int *)c->pjt;
        int *pvTarget = pjtInts + 0x64;
        pvTarget[2] = 0;
        pvTarget[1] = 0;
        pjtInts[0x64] = 0;
        break;
    }
    case 3:
        if (stateNew != 4)
            VCALL(g_2dd5bc, 278, 1);
        break;
    }
    int statePrev = c->state;
    c->state = stateNew;
    c->tState = g_2dded0[0];
    RecalcSwOxfFilterForObject(B_003DD490, c->pjt);
    switch (c->state) {
    case -1:
        SetStepRadTarget(RadYawSo(c->pjt), c->pjt);
        *(int *)(c->pjt + 0x1A4) = 0;
        break;
    case 7: {
        QW target = *(QW *)((char *)c + 0xE0);
        f.q10 = target;
        QW diff;
        QW pos = PosLoWorld(c->pjt);
        int fence7, fence8;
        asm("qmtc2.ni %1, vf2" : "=r"(fence7) : "r"(pos));
        asm("lqc2 vf1, %1\n\tvsub.xyzw vf1, vf1, vf2" : "=r"(fence8) : "m"(f.q10), "r"(fence7));
        asm("qmfc2.ni %0, vf1" : "=r"(diff) : "r"(fence8));
        SetStepRadTargetDir(c->pjt, diff);
        *(int *)(c->pjt + 0x1A4) = 0;
        break;
    }
    default:
        *(QW *)(c->pjt + 0x1E0) = g_2a2dd0;
        *(int *)(c->pjt + 0x1A4) = 1;
        break;
    }
    void *aseg = 0;
    int grfapl = 1;
    switch (c->state) {
    case -1: {
        char *pso = c->pso;
        if (pso == g_2dd5bc && *(int *)(pso + 0x1800) == 0) {
            QW four = Word(400.0f);
            f.u0.q = four;
            f.u20.q = four;
            QW posBentley = PosLoWorld(pso);
            asm("qmtc2.ni %0, vf3" : : "r"(posBentley));
            asm("sqc2 vf3, %0" : "=m"(f.q40));
            QW posOwner = PosLoWorld(c->pjt);
            QW axis = g_2a2da0;
            int lengthBits;
            int fA, fB;
            asm("qmtc2.ni %1, vf1" : "=r"(fA) : "r"(posOwner));
            asm("lqc2 vf3, %1" : "=r"(fB) : "m"(f.q40), "r"(fA));
            asm("vsub.xyzw vf3, vf3, vf1" : "=r"(fA) : "r"(fB));
            asm("lqc2 vf1, %1" : "=r"(fB) : "m"(g_2a2dc0), "r"(fA));
            asm("vmul.xyz vf2, vf3, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z" : "=r"(fA) : "r"(fB));
            asm("vmulx.xyzw vf2, vf1, vf2x" : "=r"(fB) : "r"(fA));
            asm("vsub.xyzw vf3, vf3, vf2" : "=r"(fA) : "r"(fB));
            asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r"(fB) : "r"(fA));
            float length;
            asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f"(length), "=r"(lengthBits) : "r"(fB));
            if (length < 0.0001f) {
                asm("qmtc2.ni %0, vf3" : : "r"(axis));
            } else {
                asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf3, vf3, Q");
            }
            float lift = 600.0f;
            
            QW up2 = g_2a2dc0;
            asm("lqc2 vf2, %3\n\tqmtc2.ni %2, vf1\n\tlqc2 vf4, %4\n\tvmulax.xyzw ACC, vf3, vf4x\n\tvmaddx.xyzw vf4, vf2, vf1x\n\tsqc2 vf4, %0\n\tsqc2 vf1, %1" : "=m"(f.q30), "=m"(f.u0.q) : "r"(lift), "m"(g_2a2dc0), "m"(f.u20.q));
            func_00136530(g_2dd5bc, 1);
            VCALL(g_2dd5bc, 118, f.q30);
        } else {
            if (*(char **)(pso + 0x10) == *(char **)(c->pref + 0x10)) {
                if (FIsBasicDerivedFrom(pso, 0x64)) {
                    VCALL(c->pso, 260, 4);
                } else {
                    func_001A58D0(c->pso, 0, 0xF);
                    FadeAloOut(0.25f, c->pso);
                }
            }
        }
        Carry_Detach(c->pjt + 0x900);
        if (c->pdisplay)
            VCALL(c->pdisplay, 48);
        c->pso = 0;
        return;
    }
    case 0:
        if (statePrev == 1 || statePrev == 2) {
            aseg = c->asegHold;
        } else {
            c->weight1 = 0.5f;
            c->weight0 = 0.5f;
            ReblendAsegbl(c->asegHold);
            aseg = c->asegHold;
        }
        grfapl = 9;
        break;
    case 1:
        aseg = c->asegTurnRight;
        break;
    case 2:
        aseg = c->asegTurnLeft;
        break;
    case 3:
        aseg = c->asegPickup;
        VCALL(c->pjt, 278, 1);
        break;
    case 4:
        if (c->pdisplay) {
            *(int *)(c->pdisplay + 0x154) = 1;
            *(int *)(c->pdisplay + 0x160) = 0;
            VCALL(c->pdisplay, 40);
        }
        if (statePrev == 5 || statePrev == 6) {
            aseg = c->asegAim;
        } else {
            c->tArc = 0.0f;
            c->posTarget = ConvertAloPos(c->pjt, 0, c->localAim);
            CarryThrow_UpdateArc(c, 0);
            aseg = c->asegAim;
        }
        grfapl = 9;
        c->fGoalActive = 0;
        break;
    case 5:
        aseg = c->asegAimTurnRight;
        break;
    case 6:
        aseg = c->asegAimTurnLeft;
        break;
    case 7:
        aseg = c->asegThrow;
        if (FIsBasicDerivedFrom(c->pso, 0x64))
            SpendJtGadgetPower(c->pjt, *(int *)(c->pso + 0x15C));
        break;
    }
    RetractSmaRef(c->pjt + 0x1034);
    ApplyAsegToHandle(aseg, c->pjt, grfapl, c->pjt + 0x1030, 0.0f, 1.0f);
    VCALL(c->pjt, 2D0);
    RecalcSwOxfFilterForObject(B_003DD490, c->pjt);
}
