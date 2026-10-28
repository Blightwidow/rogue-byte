// SPDX-License-Identifier: GPL-3.0-or-later
struct PALETTE { int id; unsigned char kind; signed char ccond; char pad6[2]; unsigned short cword; char pad0A[2]; unsigned *pdata; int cqw; };
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" void CBinaryInputStream_Read_thunk(void *, int, void *);
extern "C" void CBinaryInputStream_Skip(void *, int);
extern "C" int func_0013FAD0(int, void *);
extern "C" PALETTE *PidFindInIdTableB_1ed5d0(int);
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);
extern "C" void FilterColorRgba8_1ed278(unsigned *);

extern "C" void func_001EA8A8(void *pbis, PALETTE *ppalette)
{
    CBinaryInputStream_Read_thunk(pbis, 0x10, ppalette);
    unsigned cb = ppalette->cword * 4;
    if (ppalette->ccond > 0) {
        short aicond[0x80];
        CBinaryInputStream_Read_thunk(pbis, ppalette->ccond << 1, aicond);
        int fConditionsHold = func_0013FAD0(ppalette->ccond, aicond);
        if (fConditionsHold == 0) {
            if (ppalette->kind != 1)
                CBinaryInputStream_Skip(pbis, cb);
            ppalette->kind = 0;
            return;
        }
    }
    int kind = ppalette->kind;
    if (kind != 1) {
        PALETTE *ppaletteShared = PidFindInIdTableB_1ed5d0(ppalette->id);
        if (ppaletteShared != 0) {
            ppalette->pdata = ppaletteShared->pdata;
            CBinaryInputStream_Skip(pbis, cb);
        } else {
            ALLOCREQ request;
            request.cb = cb;
            request.cbAlign = 0x10;
            void *pvData = PvAllocSwImpl__Fi(&request);
            ppalette->pdata = (unsigned *)pvData;
            CBinaryInputStream_Read_thunk(pbis, cb, pvData);
            for (unsigned *pdwColor = ppalette->pdata; pdwColor < ppalette->pdata + ppalette->cword; pdwColor++)
                FilterColorRgba8_1ed278(pdwColor);
        }
    }
    ppalette->cqw = (cb + 0xf) >> 4;
}
