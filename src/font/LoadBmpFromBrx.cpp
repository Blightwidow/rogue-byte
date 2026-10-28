// SPDX-License-Identifier: GPL-3.0-or-later
struct ALLOCREQ { int cb; int cbAlign; };
struct BMP { int oid; unsigned char bmpk; signed char ccond; char pad6[10]; int cbPixels; void *pvPixels; int cqw; };
extern "C" int CBinaryInputStream_Read_thunk(void *, int, void *);
extern "C" void CBinaryInputStream_Skip(void *, int);
extern "C" int func_0013FAD0(int, short *);
extern "C" BMP *PidFindInIdTableA_1ed4e0(int);
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);

extern "C" void LoadBmpFromBrx(void *pbis, BMP *pbmp)
{
    CBinaryInputStream_Read_thunk(pbis, 0x18, pbmp);
    int ccond = pbmp->ccond;
    if (ccond > 0) {
        short aicond[0x80];
        CBinaryInputStream_Read_thunk(pbis, ccond * 2, aicond);
        int fEnabled = func_0013FAD0(pbmp->ccond, aicond);
        if (fEnabled == 0) {
            if (pbmp->bmpk != 1) {
                CBinaryInputStream_Skip(pbis, pbmp->cbPixels);
                pbmp->pvPixels = 0;
            }
            pbmp->bmpk = 0;
            return;
        }
    }
    int cb;
    if (pbmp->bmpk == 1) {
        cb = pbmp->cbPixels;
    } else {
        BMP *pbmpShared = PidFindInIdTableA_1ed4e0(pbmp->oid);
        if (pbmpShared != 0) {
            pbmp->pvPixels = pbmpShared->pvPixels;
            CBinaryInputStream_Skip(pbis, pbmp->cbPixels);
        } else {
            ALLOCREQ request;
            request.cb = pbmp->cbPixels;
            request.cbAlign = 0x10;
            void *pvPixels = PvAllocSwImpl__Fi(&request);
            pbmp->pvPixels = pvPixels;
            CBinaryInputStream_Read_thunk(pbis, pbmp->cbPixels, pvPixels);
        }
        cb = pbmp->cbPixels;
    }
    pbmp->cqw = ((unsigned)cb + 0xF) >> 4;
}
