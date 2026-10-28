// SPDX-License-Identifier: GPL-3.0-or-later
struct PALETTE { char pad0[4]; unsigned char kind; char pad5[0x1B]; };
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" int B_003DCFF8;
extern "C" PALETTE *B_003DCFFC;
extern "C" int B_003DCF9C;
extern "C" int U16Read__18CBinaryInputStream(void *);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void func_001EA8A8(void *, PALETTE *);

extern "C" void func_001EAE40(void *pbis)
{
    B_003DCFF8 = U16Read__18CBinaryInputStream(pbis);
    ALLOCREQ request;
    request.cb = B_003DCFF8 << 5;
    request.cbAlign = 0x10;
    B_003DCFFC = (PALETTE *)PvAllocStackClearImpl__Fi(&request);
    B_003DCF9C = 0;
    for (int ipalette = 0; ipalette < B_003DCFF8; ipalette++) {
        func_001EA8A8(pbis, &B_003DCFFC[ipalette]);
        if (B_003DCFFC[ipalette].kind == 1)
            B_003DCF9C = B_003DCF9C + 1;
    }
    if (B_003DCF9C < B_003DCFF8 - B_003DCF9C)
        B_003DCF9C = B_003DCFF8 - B_003DCF9C;
}
