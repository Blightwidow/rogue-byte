#include "sly2.h"
struct SMP_129408 { char b[8]; int w; };
struct CRef_129408 { int tagk; SMP_129408 *psmp; };
struct SmpBox_129408 { SMP_129408 smp; int refs; };
extern "C" {
SmpBox_129408 *PvAllocSlotheapImpl(void *);
extern char B_004521E8[];
CRef_129408 *CRef_ConstructSmp(CRef_129408 *self, SMP_129408 *psmp) {
    self->tagk = 0x1E;
    SmpBox_129408 *box = PvAllocSlotheapImpl(B_004521E8);
    box->refs = 0;
    self->psmp = &box->smp;
    box->refs++;
    *self->psmp = *psmp;
    return self;
}
}
