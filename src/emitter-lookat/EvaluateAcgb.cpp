// SPDX-License-Identifier: GPL-3.0-or-later
struct KGB { float t; float g; float gSlopeIn; float gSlopeOut; };
struct ACGB { int pad0; int ckgb; KGB *akgb; };
extern "C" void EvaluateBezierFloat(float, float, float, float, float, float, float, float *, float *);
void EvaluateAcgb(ACGB *pacgb, float *pg, float *pdg, float t, float svt)
{
    int ikgb;
    for (ikgb = 1; ikgb < pacgb->ckgb; ikgb++) {
        if (t < pacgb->akgb[ikgb].t)
            break;
    }
    KGB *pkgb = (__typeof__(&(pacgb->akgb)[0]))((ikgb) * sizeof((pacgb->akgb)[0]) + (unsigned)(pacgb->akgb));
    KGB *pkgbPrev = pkgb - 1;
    EvaluateBezierFloat(pkgb->t - pkgbPrev->t, t - pkgbPrev->t, svt, pkgbPrev->g, pkgbPrev->gSlopeOut, pkgb->g, pkgb->gSlopeIn, pg, pdg);
}
