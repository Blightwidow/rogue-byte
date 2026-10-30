/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int QW __attribute__((mode(TI)));
struct JT_18F740 { char pad[0x1A8]; float sRange; char pad2[0x18C0 - 0x1AC]; void *ptargetSmash; };
struct TARGET_18F740;
extern "C" void ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(JT_18F740 *, int, void *, float, float, float, TARGET_18F740 **, QW *);
extern "C" void FixStepAngularVelocity__FP4STEP(JT_18F740 *);
extern "C" void SetStepRadTargetDir(JT_18F740 *, QW);
extern char D_002BF4E0[];
extern "C" void ChooseJtSmashTarget__FP2JT(JT_18F740 *pjt) {
    struct { QW dir; TARGET_18F740 *ptarget; } l;
    ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(pjt, 4, D_002BF4E0, pjt->sRange, 0.25f, 3.15f, &l.ptarget, &l.dir);
    pjt->ptargetSmash = l.ptarget;
    if (l.ptarget != 0) {
        SetStepRadTargetDir(pjt, l.dir);
        FixStepAngularVelocity__FP4STEP(pjt);
    }
}
