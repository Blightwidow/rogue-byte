#include "sly2.h"
struct JT { char pad0[0x1A8]; float heading; char pad1[0x18C0 - 0x1AC]; void *target; char pad2[4]; int jts; };
struct BL { float w0; char pad[8]; float w3; };
extern "C" void ReblendAsegbl(void *);
extern "C" void SetStepRadTargetDir(void *, QW);
extern "C" void FixStepAngularVelocity__FP4STEP(void *);
extern "C" void ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(JT *, int, void *, float, float, void **, QW *, float);
extern "C" char D_002BF4C0[];
extern "C" void ChooseJtSweepTarget__FP2JTP2BLP6ASEGBL(JT *pjt, BL *pbl, void *pasegbl)
{
    struct { QW vecDir; void *ptarget; } l;
    float radMax = pjt->jts == 0 ? 3.15f : 1.6f;
    ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(pjt, 2, D_002BF4C0, pjt->heading, 0.15f, &l.ptarget, &l.vecDir, radMax);
    float blend;
    if (l.ptarget != 0) {
        float scaled = (*((float *)&l.vecDir + 2) - -50.0f) * 0.009090909f;
        if (scaled < 0.0f)
            blend = 0.0f;
        else if (scaled > 1.0f)
            blend = 1.0f;
        else
            blend = scaled;
    } else
        blend = 1.0f;
    pbl->w3 = blend;
    pbl->w0 = 1.0f - blend;
    ReblendAsegbl(pasegbl);
    pjt->target = l.ptarget;
    if (l.ptarget != 0 && pjt->jts == 0) {
        SetStepRadTargetDir(pjt, l.vecDir);
        FixStepAngularVelocity__FP4STEP(pjt);
    }
}
