struct VT { char pad[0xF8]; short delta; short index; float *(*fn)(void *); };
struct Step {
    char pad0[0xC];
    VT *vt;
    char pad1[0x180 - 0x10];
    float uTarget;
    char pad2[0x1A4 - 0x184];
    int mode;
    float radTarget;
    char pad3[0x208 - 0x1AC];
    int pxp;
    float tBase;
};
extern "C" void UpdateSo(Step *);
void UpdateStepPhys__FP4STEP(Step *);
extern "C" float atan2f(float, float);
float RadNormalize__Ff(float);
extern "C" float D_002C3C80[3];
extern "C" float g_2bbb60[2];
extern "C" float g_2dded0;

void UpdateStep(Step *step)
{
    UpdateSo(step);
    UpdateStepPhys__FP4STEP(step);
    int mode = step->mode;
    switch (mode) {
    case 0: {
        VT *vt1 = step->vt;
        float *rowY = vt1->fn((char *)step + vt1->delta);
        VT *vt2 = step->vt;
        float *rowX = vt2->fn((char *)step + vt2->delta);
        float radCurrent = atan2f(rowY[1], rowX[0]);
        float dradHeading = RadNormalize__Ff(step->radTarget - radCurrent);
        float gAbs = dradHeading < 0.0f ? -dradHeading : dradHeading;
        float uRun = D_002C3C80[0] + gAbs * (D_002C3C80[1] + gAbs * D_002C3C80[2]);
        float uMin = g_2bbb60[0];
        float uMax = g_2bbb60[1];
        if (uRun < uMin)
            uRun = uMin;
        else if (uMax < uRun)
            uRun = uMax;
        step->uTarget = uRun;
        break;
    }
    case 1:
    case -1: {
        float one = 1.0f;
        asm volatile("nop");
        step->uTarget = one;
        break;
    }
    }
    if (step->pxp != 0)
        step->tBase = g_2dded0;
}
