#include "sly2.h"
extern "C" void PredictXfTransformAdjust(void *, void *, float, void *, void *);
extern "C" void func_00230CD0(void *a, void *b, void *c, void *d)
{
    PredictXfTransformAdjust(a, b, 0.0f, c, d);
}
