/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int QW __attribute__((mode(TI)));
struct TARGET_18F688;
struct JTRange_18F688 { char pad[0x18]; float rangeNear; float rangeFar; };
struct JT_18F688 {
    char pad0[0x150];
    JTRange_18F688 *prange;
    char pad1[0x1A8 - 0x154];
    float rangeDefault;
    char pad2[0x18C0 - 0x1AC];
    TARGET_18F688 *ptargetRush;
};
extern "C" void ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(JT_18F688 *, float, int, void *, float, float, TARGET_18F688 **, QW *);
extern "C" void SetStepRadTarget(JT_18F688 *, float);
extern "C" void FixStepAngularVelocity__FP4STEP(JT_18F688 *);
extern "C" float atan2f(float, float);
extern char D_002BF4D0[];

/*
 * Retail sets up the call as a0 (pjt), f12 (rush angle), a1 (8), a3, t0, after
 * hoisting the lui constants (a2, f13, f14): the float lands before the int in
 * argument order. The callee (0x18F2B0) reads a0-a3, t0 and f12-f14: five
 * pointer/int arguments and three floats, not the Sly 1 mangled list. Declaring
 * it (JT *, float, int, VECTOR *, float, float, TARGET **, VECTOR *) gives the
 * same registers, reproduces this caller, and the matched siblings
 * ChooseJtSmashTarget (0x18F740) and ChooseJtSweepTarget (0x18F560) still score 0
 * with that order. The out-parameters share one local struct as in those siblings
 * (direction at sp+0, target at sp+0x10).
 */
extern "C" void ChooseJtRushTarget__FP2JT(JT_18F688 *pjt)
{
    struct { QW dir; TARGET_18F688 *ptarget; } l;
    JTRange_18F688 *prange = pjt->prange;
    float rushAngle;
    if (prange != 0 && 0.5f < prange->rangeFar) {
        rushAngle = prange->rangeNear;
    } else {
        rushAngle = pjt->rangeDefault;
    }
    ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(pjt, rushAngle, 8, D_002BF4D0, 0.25f, 1.0f, &l.ptarget, &l.dir);
    pjt->ptargetRush = l.ptarget;
    if (l.ptarget != 0) {
        rushAngle = atan2f(((float *)&l.dir)[1], ((float *)&l.dir)[0]);
    }
    SetStepRadTarget(pjt, rushAngle);
    FixStepAngularVelocity__FP4STEP(pjt);
}
