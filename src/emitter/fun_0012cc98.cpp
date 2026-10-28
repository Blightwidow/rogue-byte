// SPDX-License-Identifier: GPL-3.0-or-later
struct ACGC { int pad; float g; };
extern "C" void func_0012CC98(ACGC *pacgc, float *pg, float *pdg)
{
    if (pg != 0)
        *pg = pacgc->g;
    if (pdg != 0)
        *pdg = 0.0f;
}
