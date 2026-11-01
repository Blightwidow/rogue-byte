#include "sly2.h"
struct LM_129398 { char b[8]; };
struct CRef_129398 { int tagk; LM_129398 *plm; };
struct LmBox_129398 { LM_129398 lm; int refs; };
extern "C" {
LmBox_129398 *PvAllocSlotheapImpl(void *);
extern char B_004521D0[];
CRef_129398 *CRef_ConstructLm(CRef_129398 *self, LM_129398 *plm) {
    self->tagk = 0x1D;
    LmBox_129398 *box = PvAllocSlotheapImpl(B_004521D0);
    box->refs = 0;
    self->plm = &box->lm;
    box->refs++;
    *self->plm = *plm;
    return self;
}
}
