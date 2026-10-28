#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct REC { char *name; int a; int b; int c; char blk[0x40]; };
struct LOX { char pad[0x50]; int crec; REC *arec; };
extern "C" {
void LoadLoFromBrx(LOX *, Bis *);
unsigned U8Read__18CBinaryInputStream(Bis *);
int S8Read__18CBinaryInputStream(Bis *);
int S32Read__18CBinaryInputStream(Bis *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void func_00118380(Bis *, REC *, void *, int);
void func_00118458(Bis *, void *);
extern char g_2dd590;
}
extern "C" void func_00153B08(LOX *plo, Bis *pbis)
{
    LoadLoFromBrx(plo, pbis);
    int crec = U8Read__18CBinaryInputStream(pbis);
    ALLOCREQ req;
    req.cb = crec * 0x50;
    req.cbAlign = 0x10;
    plo->crec = crec;
    plo->arec = (REC *)PvAllocSwClearImpl__Fi(&req);
    for (int irec = 0; irec < plo->crec; irec++) {
        REC *prec = plo->arec + irec;
        func_00118380(pbis, prec, &g_2dd590, 7);
        prec->a = S8Read__18CBinaryInputStream(pbis);
        prec->b = S32Read__18CBinaryInputStream(pbis);
        prec->c = S32Read__18CBinaryInputStream(pbis);
        func_00118458(pbis, prec->blk);
    }
}
