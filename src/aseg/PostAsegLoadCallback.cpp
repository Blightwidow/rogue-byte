// SPDX-License-Identifier: GPL-3.0-or-later
struct ASEG;
struct ALO;
struct ASEGDEFAULT { float tLocal; float svtLocal; int grfapl; };
extern "C" void ApplyAseg(ASEG *, ALO *, float, float, int, void *);
extern "C" void PostAsegLoadCallback(ASEG *paseg, ASEGDEFAULT *pdefault)
{
    ApplyAseg(paseg, 0, pdefault->tLocal, pdefault->svtLocal, pdefault->grfapl, 0);
}
