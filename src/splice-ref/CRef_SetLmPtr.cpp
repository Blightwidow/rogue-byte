#include "sly2.h"
struct LM_129878 { char b[8]; };
struct CRef_129878 { int tagk; LM_129878 *plm; };
struct LmBox_129878 { LM_129878 lm; int refs; };
extern "C" {
void CRef_Destruct(CRef_129878 *);
LmBox_129878 *PvAllocSlotheapImpl(void *);
extern char B_004521D0[];
CRef_129878 *CRef_SetLmPtr(CRef_129878 *self, LM_129878 *plm) {
    CRef_Destruct(self);
    self->tagk = 0x1D;
    LmBox_129878 *box = PvAllocSlotheapImpl(B_004521D0);
    box->refs = 0;
    self->plm = &box->lm;
    box->refs++;
    *self->plm = *plm;
    return self;
}
}
