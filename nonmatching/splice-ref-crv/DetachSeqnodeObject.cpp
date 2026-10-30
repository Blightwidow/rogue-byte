// SPDX-License-Identifier: GPL-3.0-or-later
struct SOVT { char pad[0x2A0]; short delta; short idx; void (*fn)(void *, int, int); };
struct SO { char pad0[0xC]; SOVT *vt; };
struct SEQNODE { char pad0[0xA4]; int cattach; SO *aso[4]; };
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void *memmove(SEQNODE *, const void *, unsigned);

extern "C" void DetachSeqnodeObject(SEQNODE *pseqnode, SO *pso, int n1, int n2)
{
    if (FIsBasicDerivedFrom(pso, 0x33) == 0)
        return;
    int cattach = pseqnode->cattach;
    int iattach = 0;
    while (iattach < cattach && pseqnode->aso[iattach] != pso)
        iattach++;
    if (iattach < cattach) {
        char *pbase = (char *)pseqnode + iattach * 4;
        memmove(pseqnode, pbase + 0xAC, (cattach - iattach) * 4 - 4);
        pseqnode->cattach--;
        pso->vt->fn((char *)pso + pso->vt->delta, n1, n2);
    }
}
