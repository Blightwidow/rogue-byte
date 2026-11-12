// SPDX-License-Identifier: GPL-3.0-or-later
#include "bis.h"
#include "alloc.h"
struct LEVELROW { u8 ab[64]; };
struct LEVELLIST { s32 c; s16 *as; };
extern "C" {
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void func_00118458(CBinaryInputStream *, void *);
extern s32 B_003E1C38;
extern s32 B_003E1C3C;
extern LEVELROW *B_003E1C40;
extern s32 *B_003E1C44;
extern s32 *B_003E1C48;
extern LEVELLIST *B_003E1C4C;
extern LEVELROW *B_003E1C50;
}
static inline void *PvAllocSw(ALLOCREQ *preq, int cb, int cbAlign)
{
    preq->cb = cb;
    preq->cbAlign = cbAlign;
    return PvAllocSwImpl__Fi(preq);
}
extern "C" void LoadLevelTableFromBrx(void *unused, CBinaryInputStream *pbis)
{
    ALLOCREQ req;
    B_003E1C38 = pbis->U32Read();
    B_003E1C3C = pbis->U32Read();
    B_003E1C40 = (LEVELROW *)PvAllocSw(&req, B_003E1C38 << 6, 0x10);
    B_003E1C44 = (s32 *)PvAllocSw(&req, B_003E1C38 * 4, 0x10);
    B_003E1C48 = (s32 *)PvAllocSw(&req, B_003E1C38 * 4, 0x10);
    B_003E1C4C = (LEVELLIST *)PvAllocSw(&req, B_003E1C38 * 8, 0x10);
    req.cb = 0x240;
    req.cbAlign = 0x10;
    B_003E1C50 = (LEVELROW *)PvAllocSwClearImpl__Fi(&req);
    for (int i = 0; i < B_003E1C38; i++) {
        func_00118458(pbis, &B_003E1C40[i]);
        B_003E1C44[i] = pbis->U8Read();
        B_003E1C48[i] = pbis->U8Read();
        if (pbis->U8Read())
            B_003E1C50[B_003E1C44[i]] = B_003E1C40[i];
        LEVELLIST *plist = &B_003E1C4C[i];
        plist->c = pbis->U8Read();
        plist->as = (s16 *)PvAllocSw(&req, plist->c * 2, 0x10);
        for (int j = 0; j < plist->c; j++)
            plist->as[j] = pbis->U16Read();
    }
}
