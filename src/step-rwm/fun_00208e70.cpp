/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
extern "C" {
extern const float D_FLT_002C3D90;
extern const float D_FLT_002C3D94;
void GetJtFocusScore(void *, void *, void *, float *, float *);
unsigned long GrfsgsFromSgs(int);
int FIsGuardInSgs(void *, int);
void *func_00205458(void *, int);
int FIsBasicDerivedFrom(void *, int);
int func_00227C90(void *, QW);
QW PosLoWorld(void *);
int FCheckLm__FP2LMf(void *, float);
#define P(base, off) (*(void **)((char *)(base) + (off)))
#define I(base, off) (*(int *)((char *)(base) + (off)))
#define F(base, off) (*(float *)((char *)(base) + (off)))
int func_00208E70(void *guard, void *jt, float *ps)
{
    float sg[2];
    GetJtFocusScore(jt, guard, (char *)jt + 0x10DC, &sg[0], &sg[1]);
    if (ps != 0)
        *ps = sg[0];
    if ((*(unsigned long *)((char *)guard + 0x2C0) & GrfsgsFromSgs(1)) == 0) {
        if (I(guard, 0x364) != 0 && I(jt, 0x10F0) != 0) {
            void *held;
            if (FIsGuardInSgs(guard, 0x1D)) {
                held = P(guard, 0x38C);
            } else if (FIsGuardInSgs(guard, 5)) {
                held = P(func_00205458(guard, 0xA1), 0x50);
            } else if (FIsGuardInSgs(guard, 6)) {
                held = P(func_00205458(guard, 0xA2), 0x50);
            } else if (FIsGuardInSgs(guard, 0x17)) {
                held = P(func_00205458(guard, 0xB1), 0x5C);
                if (held == jt)
                    *ps = *ps + D_FLT_002C3D90;
            } else {
                held = 0;
            }
            if (held != 0) {
                if (held == jt)
                    return 4;
                if (FIsBasicDerivedFrom(held, 0x34))
                    return 4;
            }
        }
        void *volume;
        if (guard == P(jt, 0x10DC) && I(jt, 0x10E4) == 3)
            volume = P(guard, 0x3F8);
        else
            volume = P(guard, 0x3F4);
        if (volume != 0 && ((int)(*(unsigned long *)((char *)volume + 0x28) >> 60) & 1) != 0) {
            if (func_00227C90(volume, PosLoWorld(jt)))
                return 3;
        }
    }
    void *plm = FIsGuardInSgs(guard, 0x17) ? (char *)guard + 0x368 : (char *)guard + 0x370;
    if (sg[0] <= F(guard, 0x378) * D_FLT_002C3D94 && FCheckLm__FP2LMf(plm, sg[1]) && I(guard, 0x364) != 0)
        return 2;
    if (sg[0] <= F(guard, 0x388)) {
        if (!FCheckLm__FP2LMf((char *)guard + 0x380, sg[1]))
            return 0;
        if (I(guard, 0x37C) != 0)
            return 1;
    }
    return 0;
}
}
