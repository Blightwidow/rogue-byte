// SPDX-License-Identifier: GPL-3.0-or-later
struct LO1A5270 {
    char pad0[0x10];
    LO1A5270 *pparent;
    int root;
    char pad18[0x28 - 0x18];
    unsigned long grf;
    char pad30[0x38 - 0x30];
    float gDefault;
    int oid;
    int flags;
};
extern int B_003E139C;
extern "C" {
void func_001A53A0(LO1A5270 *);
void func_001A5448(LO1A5270 *, int *, int **);
void InsertDlEntryBefore(int, int, LO1A5270 *);
}
extern "C" void InitLo__FP2LO(LO1A5270 *plo)
{
    int *pdl;
    int *ppfirst;
    LO1A5270 *pparent = plo->pparent;
    plo->gDefault = 1.0e10f;
    unsigned long grf = plo->grf;
    grf |= 0x000F000000000000UL;
    grf &= ~0x00F0000000000000UL;
    grf |= 0x0020000000000000UL;
    plo->grf = grf;
    ((unsigned char *)plo)[0x2D] = 0xFF;
    if (pparent != 0) {
        plo->root = pparent->root;
        unsigned bit = (unsigned)(pparent->grf >> 60) & 1;
        plo->grf = (plo->grf & ~0x1000000000000000UL) | ((unsigned long)bit << 60);
    } else {
        func_001A53A0(plo);
        plo->grf |= 0x1000000000000000UL;
    }
    plo->flags = 0x21;
    int oid;
    if (plo->pparent)
        oid = plo->pparent->oid;
    else
        oid = B_003E139C;
    plo->oid = oid;
    func_001A5448(plo->pparent, (int *)&pdl, (int **)&ppfirst);
    InsertDlEntryBefore((int)pdl, *ppfirst, plo);
}
