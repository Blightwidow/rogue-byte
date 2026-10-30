#include "sly2.h"
extern "C" {
void ApplyAsegToHandle(float, float, int, void *, int, void *);
void FixStepAngularVelocity__FP4STEP(void *);
void *PchnFindAseg(void *, void *, int, int);
int *PeaFindAsegLabel(int, int);
QW PosLoWorld(void *, ...);
float RadNormalize__Ff(float);
void RetractAsegaHandle(void *);
void RetractSmaRef(void *);
void SetStepRadTarget(void *, float);
float atan2f(float, float);
void func_00131A90(void *, float);
void func_001431D0(void *);
extern const float RO_002C09F0;
extern QW g_2a2dd0;
}
struct Clock { float time; float dt; };
extern Clock g_2dded0;
struct VT_1B86B0 { char pad[0x18]; short delta; short pad1A; void (*fn)(void *, void *, int, void *, float, float); };
struct OBJ_1B86B0 { VT_1B86B0 *vt; };
#define F(type, base, off) (*(type *)((char *)(base) + (off)))

extern "C" void SetMurrayAttackState(void *m, int attack)
{
    char sp[0x30] __attribute__((aligned(16)));
    if (attack == F(int, m, 0x1810))
        return;
    F(int, m, 0x1810) = attack;
    F(float, m, 0x1814) = g_2dded0.time;
    if (attack == -1)
        return;
    F(int, m, 0x1820) = 0;
    F(int, m, 0x1818) = 0;
    F(int, m, 0x181C) = 0;
    if (F(int, m, 0x190C) != 0)
        RetractAsegaHandle((char *)m + 0x190C);
    int paseg = F(int, (char *)m + attack * 4, 0x17FC);
    void *target = F(void *, m, 0x10DC);
    F(QW, m, 0x190) = g_2a2dd0;
    if (target != 0 && F(int, m, 0x10E4) >= 2 && !(F(int, F(void *, m, 0x150), 0x30) & 8)) {
        *(QW *)(sp + 0x20) = PosLoWorld(target, target);
        QW pos = PosLoWorld(m);
        QW diff;
        float fx, fy;
        asm("qmtc2.ni %0, vf2" : : "r" (pos));
        asm("lqc2 vf1, 0x20(%0)" : : "r" (sp));
        asm("vsub.xyzw vf1, vf1, vf2");
        asm volatile("qmfc2.ni %0, vf1" : "=r" (diff));
        QW rotated = __builtin_prot3w(diff);
        asm("mtc1 %2, %0\n\tmtc1 %3, %1" : "=f" (fx), "=f" (fy) : "r" (diff), "r" (rotated));
        float rad = atan2f(fy, fx);
        if (__builtin_fabsf(RadNormalize__Ff(rad - F(float, m, 0x1A8))) < RO_002C09F0) {
            SetStepRadTarget(m, rad);
            FixStepAngularVelocity__FP4STEP(m);
        }
    }
    float tStart = 0.0f;
    RetractSmaRef((char *)m + 0x1034);
    ApplyAsegToHandle(tStart, 1.0f, paseg, m, 1, (char *)m + 0x1030);
    if (paseg != 0) {
        float *label = (float *)PeaFindAsegLabel(paseg, 0x1AC);
        if (label != 0)
            tStart = *label;
    }
    if (tStart != 0.0f) {
        void *pah = F(void *, m, 0x1030);
        func_00131A90(pah, g_2dded0.time + tStart / F(float, pah, 0x40));
    }
    void *pah2 = F(void *, m, 0x1030);
    if (pah2 != 0) {
        void *pchn = PchnFindAseg(F(void *, pah2, 0x14), m, 1, 1);
        if (pchn != 0) {
            OBJ_1B86B0 *obj = F(OBJ_1B86B0 *, pchn, 4);
            obj->vt->fn((char *)obj + obj->vt->delta, sp, 0, obj, 0.0f, 0.0f);
            OBJ_1B86B0 *obj2 = F(OBJ_1B86B0 *, pchn, 4);
            obj2->vt->fn((char *)obj2 + obj2->vt->delta, sp + 0x10, 0, obj2, F(float, F(void *, F(void *, m, 0x1030), 0x14), 0x74), 0.0f);
            QW worldPos = PosLoWorld(m);
            char *frame = (char *)m + 0x1B0;
            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf3, vf3, vf1");
            asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(frame));
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(frame));
            asm volatile("lqc2 vf1, 0x1b0(%0)" : : "r"(m));
            asm volatile("vmulax.xyz ACC, vf1, vf3x");
            asm volatile("vmadday.xyz ACC, vf4, vf3y");
            asm volatile("vmaddz.xyz vf3, vf5, vf3z");
            asm volatile("qmtc2.ni %0, vf1" : : "r"(worldPos));
            asm volatile("vadd.xyzw vf2, vf1, vf3");
            asm volatile("sqc2 vf2, 0x1830(%0)" : : "r"(m));
        } else {
            F(QW, m, 0x1830) = PosLoWorld(m, sp);
        }
    }
    func_001431D0(m);
}
