/* SPDX-License-Identifier: GPL-3.0-or-later */
struct SMP;
extern "C" float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
extern "C" float RadNormalize__Ff(float);
extern "C" float RadSmooth__FfffP3SMPPf(float radCurrent, float radTarget, float dt, SMP *psmp, float *pdradSmooth) {
    return RadNormalize__Ff(radCurrent + GSmooth__FfffP3SMPPf(0.0f, RadNormalize__Ff(radTarget - radCurrent), dt, psmp, pdradSmooth));
}
