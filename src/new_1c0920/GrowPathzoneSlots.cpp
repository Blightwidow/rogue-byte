// SPDX-License-Identifier: GPL-3.0-or-later
struct ALLOCREQ { int cb; int cbAlign; };
struct EP { float g; short fMin; short islot; };
struct PZ { char pad[0xFC]; int cslot; int cep; EP *aepX; EP *aepY; int *aslot; };
extern "C" {
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void CopyAb__FPvT0Ui(void *, void *, unsigned int);
void *memset(void *, int, unsigned int);
}
// Retail: the slot count goes 0 -> 0x10 -> 0x80 through a switch whose decision tree is rooted at 0x10 (beq 0x10, slti 0x11,
// movz for 0): gcc 2.95 only balances that way with three case nodes, so the source keeps a `case 0x80` that changes nothing
// (its test folds into the default jump). The memset loads pz->cslot into $a2, forms the address first as shift + base
// (addu $a0,$a0,$s0) and shifts the size in the delay slot: that takes the size in its own unsigned local and the address
// as integer arithmetic; `aslot + cslotOld` gives addu with the operands swapped.
extern "C" void GrowPathzoneSlots(PZ *pz)
{
    int cslotNew;
    switch (pz->cslot) {
    case 0: cslotNew = 0x10; break;
    case 0x10: cslotNew = 0x80; break;
    case 0x80: break;
    }
    ALLOCREQ req;
    req.cb = (cslotNew * 2 + 2) * sizeof(EP);
    req.cbAlign = 0x10;
    EP *aepX = (EP *)PvAllocSwImpl__Fi(&req);
    req.cb = (cslotNew * 2 + 2) * sizeof(EP);
    req.cbAlign = 0x10;
    EP *aepY = (EP *)PvAllocSwImpl__Fi(&req);
    req.cb = cslotNew * sizeof(int);
    req.cbAlign = 0x10;
    int *aslot = (int *)PvAllocSwImpl__Fi(&req);
    CopyAb__FPvT0Ui(aepX, pz->aepX, pz->cep * sizeof(EP));
    CopyAb__FPvT0Ui(aepY, pz->aepY, pz->cep * sizeof(EP));
    CopyAb__FPvT0Ui(aslot, pz->aslot, pz->cslot * sizeof(int));
    int cslotOld = pz->cslot;
    unsigned int cb = (cslotNew - cslotOld) * sizeof(int);
    memset((void *)((cslotOld << 2) + (int)aslot), 0, cb);
    pz->aepY = aepY;
    pz->aslot = aslot;
    pz->cslot = cslotNew;
    pz->aepX = aepX;
    if (pz->cep == 0) {
        aepX[0].g = -3.402823466e+38f;
        pz->aepX[0].fMin = 1;
        pz->aepX[0].islot = 0xFF;
        pz->aepX[1].g = 3.402823466e+38f;
        pz->aepX[1].fMin = 0;
        pz->aepX[1].islot = 0xFF;
        pz->aepY[0].g = -3.402823466e+38f;
        pz->aepY[0].fMin = 1;
        pz->aepY[0].islot = 0xFF;
        pz->aepY[1].g = 3.402823466e+38f;
        pz->aepY[1].fMin = 0;
        pz->aepY[1].islot = 0xFF;
        pz->cep = 2;
    }
}
