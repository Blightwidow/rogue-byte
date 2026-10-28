// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CM { char pad[0x240]; float nearClip; float farClip; float fogDensity; };
struct FGFN { float f0; float f1; float f2; float f3; };
void FitRecipFunction(float, float, float, float, float *, float *);
void BuildCmFgfn(CM *cm, float scale, FGFN *fgfn)
{
    if (scale == 3.402823466e+38f)
        scale = 1.0f;
    FitRecipFunction(1.0f, 4080.0f, cm->farClip / cm->nearClip, (1.0f - cm->fogDensity * scale) * 4080.0f, &fgfn->f0, &fgfn->f1);
    float biased = fgfn->f0 + 8417280.0f;
    fgfn->f0 = biased;
    fgfn->f2 = cm->nearClip;
    fgfn->f3 = biased + 8192.0f;
}
