// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LM { float lo; float hi; };
struct EMITVX { int perRing; float tiltStep; float panStep; float tiltMin; float panMin; };
float RadNormalize(float);
extern "C" float GRandInRange(float, float);
void CalculateEmitvx(int cParticlePerRing, LM *plm, int cParticle, EMITVX *pemitvx)
{
    if (cParticlePerRing > 0) {
        pemitvx->perRing = cParticlePerRing = (cParticlePerRing < cParticle) ? cParticlePerRing : cParticle;
    } else
        pemitvx->perRing = cParticle;
    int perRing = pemitvx->perRing;
    int last = cParticle - 1;
    int rings = (last + perRing) / perRing;
    float tilt = RadNormalize(plm->hi - plm->lo) / (float)rings;
    pemitvx->panStep = 6.2831855f / (float)pemitvx->perRing;
    pemitvx->tiltStep = tilt;
    pemitvx->tiltMin = plm->lo + tilt * 0.5f;
    pemitvx->panMin = GRandInRange(0.0f, 6.2831855f);
}
