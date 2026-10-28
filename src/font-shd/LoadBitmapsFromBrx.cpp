// SPDX-License-Identifier: GPL-3.0-or-later
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" int B_003DCFF0;
extern "C" char *B_003DCFF4;
extern "C" int B_003DCF98;
extern "C" int U16Read__18CBinaryInputStream(void *);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void LoadBmpFromBrx(void *, char *);

extern "C" void LoadBitmapsFromBrx(void *pbis)
{
    B_003DCFF0 = U16Read__18CBinaryInputStream(pbis);
    ALLOCREQ request;
    request.cb = B_003DCFF0 * 0x28;
    request.cbAlign = 0x10;
    B_003DCFF4 = (char *)PvAllocStackClearImpl__Fi(&request);
    B_003DCF98 = 0;
    for (int ibmp = 0; ibmp < B_003DCFF0; ibmp++) {
        int ibyte = ibmp * 0x28;
        LoadBmpFromBrx(pbis, B_003DCFF4 + ibyte);
        if ((unsigned char)B_003DCFF4[ibyte + 4] == 1)
            B_003DCF98 = B_003DCF98 + 1;
    }
    if (B_003DCF98 < B_003DCFF0 - B_003DCF98)
        B_003DCF98 = B_003DCFF0 - B_003DCF98;
}
