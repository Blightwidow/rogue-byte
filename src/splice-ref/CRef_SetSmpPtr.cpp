#include "sly2.h"
struct P8 { char b[8]; };
struct SM_1298F0 { P8 head; int tail; };
struct CRef_1298F0 { int tagk; SM_1298F0 *psm; };
struct SmBox_1298F0 { SM_1298F0 sm; int refs; };
extern "C" {
void CRef_Destruct(CRef_1298F0 *);
SmBox_1298F0 *PvAllocSlotheapImpl(void *);
extern char B_004521E8[];
CRef_1298F0 *CRef_SetSmpPtr(CRef_1298F0 *self, SM_1298F0 *psm) {
    CRef_Destruct(self);
    self->tagk = 0x1E;
    SmBox_1298F0 *box = PvAllocSlotheapImpl(B_004521E8);
    box->refs = 0;
    self->psm = &box->sm;
    box->refs++;
    *self->psm = *psm;
    return self;
}
}
