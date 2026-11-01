#include "sly2.h"
extern "C" {
QW ConvertXfVec(void *, void *, QW);
int FFloatsNear__Ffff(float, float, float);
void LoadRotateMatrix(void *, QW);
void WakeXf(void *, void *);
void __as__6VECTORG9VU_VECTOR(void *, QW);
void func_001F4BF8(void *);
extern char B_003DD490[];
extern QW g_2a2dd0;
}
struct VT1FA528 { char pad[0x90]; short delta; short index; void (*fn)(void *); };
// lane 0 of a QW to an FP register
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }
// lane 1 of a QW (prot3w rotates it to lane 0), then mtc1
static inline float Lane1(QW q) { QW t; asm("prot3w %0, %1" : "=r"(t) : "r"(q)); return Lane0(t); }
// lane 2 of a QW (pextuw with $zero), then mtc1
static inline float Lane2(QW q) { QW t; asm("pextuw %0, $0, %1" : "=r"(t) : "r"(q)); return Lane0(t); }

// 1 when all three lanes of a and b are within 1e-4
static inline int FSameXyz(QW a, QW b)
{
    int same = 0;
    if (FFloatsNear__Ffff(Lane0(a), Lane0(b), 0.0001f) != 0 && FFloatsNear__Ffff(Lane1(a), Lane1(b), 0.0001f) != 0)
        same = FFloatsNear__Ffff(Lane2(a), Lane2(b), 0.0001f) != 0;
    return same;
}

#define AT(base, offset) (*(QW *)((char *)(base) + (offset)))
#define WORD(base, offset) (*(int *)((char *)(base) + (offset)))
void func_001FA528(char *self)
{
    char buf[0xC0] __attribute__((aligned(16)));
    int changed = 0;
    if (WORD(self, 0xE8) != 0) {
        QW vecA = AT(self, 0xF0);
        QW rest = g_2a2dd0;
        if (!FSameXyz(rest, vecA)) {
            char *target = *(char **)(self + 0x58);
            char *vecPtr = self + 0xF0;
            changed = 1;
            WakeXf(self, target);
            QW moved = ConvertXfVec(0, *(char **)(target + 0xA0), AT(self, 0xF0));
            WORD(vecPtr, 4) = 0;
            asm("qmtc2.ni %0, vf2" : : "r"(moved));
            WORD(vecPtr, 8) = 0;
            WORD(self, 0xF0) = 0;
            asm("lqc2 vf1, 0x30(%0)" : : "r"(target));
            asm("vadd.xyzw vf2, vf1, vf2");
            QW sum;
            asm("qmfc2.ni %0, vf2" : "=r"(sum));
            __as__6VECTORG9VU_VECTOR(target + 0x30, sum);
            *(float *)(target + 0x3C) = 1.0f;
            char *world = B_003DD490;
            int stamp = WORD(world, 0x3D58) + 1;
            WORD(world, 0x3D58) = stamp;
            WORD(target, 0xA4) = stamp;
        }
        QW vecB = AT(self, 0x100);
        QW rest2 = g_2a2dd0;
        if (!FSameXyz(rest2, vecB)) {
            char *target = *(char **)(self + 0x5C);
            char *vecPtr = self + 0x100;
            changed = 1;
            WakeXf(self, target);
            QW moved = ConvertXfVec(0, *(char **)(target + 0xA0), AT(self, 0x100));
            WORD(vecPtr, 8) = 0;
            WORD(vecPtr, 4) = 0;
            WORD(self, 0x100) = 0;
            LoadRotateMatrix(buf + 0x60, moved);
            asm("lqc2 vf6, %0" : : "m"(AT(target, 0)));
            asm("lqc2 vf3, %0" : : "m"(AT(buf, 0x60)));
            asm("lqc2 vf5, %0" : : "m"(AT(buf, 0x70)));
            asm("lqc2 vf4, %0" : : "m"(AT(buf, 0x80)));
            asm("vmulax.xyz ACC, vf3, vf6x\n\tvmadday.xyz ACC, vf5, vf6y\n\tvmaddz.xyz vf6, vf4, vf6z");
            asm("sqc2 vf6, %0" : "=m"(AT(buf, 0x30)));
            asm("sqc2 vf6, %0" : "=m"(AT(buf, 0x90)));
            asm("lqc2 vf1, %0" : : "m"(AT(target, 0x10)));
            asm("vmulax.xyz ACC, vf3, vf1x\n\tvmadday.xyz ACC, vf5, vf1y\n\tvmaddz.xyz vf1, vf4, vf1z");
            asm("sqc2 vf1, %0" : "=m"(AT(buf, 0x40)));
            asm("sqc2 vf1, %0" : "=m"(AT(buf, 0xA0)));
            asm("lqc2 vf2, %0" : : "m"(AT(target, 0x20)));
            asm("vmulax.xyz ACC, vf3, vf2x\n\tvmadday.xyz ACC, vf5, vf2y\n\tvmaddz.xyz vf3, vf4, vf2z");
            asm("sqc2 vf1, %0" : "=m"(AT(buf, 0x10)));
            asm("sqc2 vf3, %0" : "=m"(AT(buf, 0x20)));
            asm("sqc2 vf3, %0" : "=m"(AT(buf, 0xB0)));
            asm("sqc2 vf3, %0" : "=m"(AT(buf, 0x50)));
            asm("sqc2 vf6, %0" : "=m"(AT(buf, 0x0)));
            asm("sqc2 vf6, %0" : "=m"(AT(target, 0)));
            AT(target, 0x10) = AT(buf, 0x10);
            WORD(target, 0x1C) = 0;
            AT(target, 0x20) = AT(buf, 0x20);
            WORD(target, 0x2C) = 0;
            WORD(target, 0xC) = 0;
            char *world = B_003DD490;
            int stamp = WORD(world, 0x3D58) + 1;
            WORD(world, 0x3D58) = stamp;
            WORD(target, 0xA4) = stamp;
        }
        if (changed != 0) {
            VT1FA528 *vt = *(VT1FA528 **)(self + 0xC);
            vt->fn(self + vt->delta);
            func_001F4BF8(self);
        }
    }
}
