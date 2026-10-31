#include "sly2.h"
struct CRef_129248 { int tagk; QW *pv; };
struct VecBox_129248 { QW value; int refs; };
extern "C" {
VecBox_129248 *PvAllocSlotheapImpl(void *);
extern char B_00452188[];
CRef_129248 *CRef_ConstructVectorValue(CRef_129248 *self, QW value) {
    self->tagk = 0x1A;
    VecBox_129248 *box = PvAllocSlotheapImpl(B_00452188);
    box->refs = 0;
    self->pv = &box->value;
    box->refs++;
    *self->pv = value;
    return self;
}
}
