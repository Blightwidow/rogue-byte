// SPDX-License-Identifier: GPL-3.0-or-later
struct KGB { float t; float g; float gSlopeIn; float gSlopeOut; };
struct ACGB { int pad0; int ckgb; KGB *akgb; };
extern "C" void EvaluateBezierFloat(float, float, float, float, float, float, float, float *, float *);
void EvaluateAcgb(ACGB *pacgb, float *pg, float *pdg, float t, float svt)
{
    int ckgb = pacgb->ckgb;
    int ikgb = 1;
    if (ikgb < ckgb) {
        KGB *p = pacgb->akgb + 1;
        if (t < p->t) goto done;
        ikgb++;
        do {
            if (!(ikgb < ckgb)) break;
            p++;
            if (t < p->t) break;
            ikgb++;
        } while (1);
    }
done:
    KGB *pkgb = &pacgb->akgb[ikgb];
    KGB *pkgbPrev = pkgb - 1;
    EvaluateBezierFloat(pkgb->t - pkgbPrev->t, t - pkgbPrev->t, svt, pkgbPrev->g, pkgbPrev->gSlopeOut, pkgb->g, pkgb->gSlopeIn, pg, pdg);
}
