// SPDX-License-Identifier: GPL-3.0-or-later
struct LO {
    char pad0[0x10];
    LO *pparent;
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
void func_001A53A0(LO *);
void func_001A5448(LO *, int *, int **);
void InsertDlEntryBefore(int, int, LO *);
}
union FB { int i; float f; };
void InitLo(LO *plo)
{
    int *pdl;
    int *ppfirst;
    LO *pparent = plo->pparent;
    plo->gDefault = 1.0e10f;
    unsigned long grf = plo->grf;
    grf |= 0x000F000000000000UL;
    asm("" : "+r"(grf));
    unsigned long m1;
    asm("ori %0, $0, 0xFF0F\n\tdsll %0, %0, 16\n\tori %0, %0, 0xFFFF\n\tdsll %0, %0, 16\n\tori %0, %0, 0xFFFF\n\tdsll %0, %0, 16\n\tori %0, %0, 0xFFFF" : "=r"(m1));
    grf &= m1;
    asm("" : "+r"(grf));
    grf |= 0x0020000000000000UL;
    plo->grf = grf;
    ((unsigned char *)plo)[0x2D] = 0xFF;
    unsigned long m2;
    if (pparent != 0) {
        asm("ori %0, $0, 0xEFFF\n\tdsll %0, %0, 16\n\tori %0, %0, 0xFFFF\n\tdsll %0, %0, 16\n\tori %0, %0, 0xFFFF\n\tdsll %0, %0, 16\n\tori %0, %0, 0xFFFF" : "=r"(m2));
        plo->root = pparent->root;
        unsigned long bit = (pparent->grf >> 60) & 1;
        asm("" : "+r"(bit));
        plo->grf = (plo->grf & m2) | (bit << 60);
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
