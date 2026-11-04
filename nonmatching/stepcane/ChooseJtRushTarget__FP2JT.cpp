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
extern "C" void ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(JT_18F688 *, int, void *, float, float, float, TARGET_18F688 **, QW *);
extern "C" void SetStepRadTarget(JT_18F688 *, float);
extern "C" void FixStepAngularVelocity__FP4STEP(JT_18F688 *);
extern "C" float atan2f(float, float);
extern char D_002BF4D0[];

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
    ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(pjt, 8, D_002BF4D0, rushAngle, 0.25f, 1.0f, &l.ptarget, &l.dir);
    pjt->ptargetRush = l.ptarget;
    if (l.ptarget != 0) {
        rushAngle = atan2f(((float *)&l.dir)[1], ((float *)&l.dir)[0]);
    }
    SetStepRadTarget(pjt, rushAngle);
    FixStepAngularVelocity__FP4STEP(pjt);
}
