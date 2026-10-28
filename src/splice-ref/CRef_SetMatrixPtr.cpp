#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct MATRIX { QW row[4]; };
struct MATBOX { MATRIX matrix; int cref; };
struct CRef { int tagk; MATBOX *pbox; int pad8; int padc; };
struct SLOTHEAP;
extern SLOTHEAP B_004521A0;
extern "C" void CRef_Destruct(CRef *);
extern "C" void *PvAllocSlotheapImpl(SLOTHEAP *);

CRef *CRef_SetMatrixPtr(CRef *self, MATRIX *pmatrix)
{
    CRef_Destruct(self);
    self->tagk = 0x1B;
    MATBOX *pbox = (MATBOX *)PvAllocSlotheapImpl(&B_004521A0);
    pbox->cref = 0;
    self->pbox = pbox;
    pbox->cref = pbox->cref + 1;
    self->pbox->matrix = *pmatrix;
    return self;
}
