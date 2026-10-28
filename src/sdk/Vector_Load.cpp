#include "sly2.h"
struct CBinaryInputStream { int S32Read(); };
struct ALLOCREQ { int cb; int align; };
struct VT { char pad[0x10]; short d0; short i0; void (*fnClear)(void *); char pad1[0x20 - 0x18]; short d1; short i1; void (*fnRead)(void *, void *, CBinaryInputStream *); short d2; short i2; void (*fnAdd)(void *, void *); };
struct VEC { char pad[0xC]; VT *vt; char ary[1]; };
extern "C" int CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern "C" void CAry_Reserve(void *, int);
extern "C" void Vector_Load(VEC *pvec, CBinaryInputStream *pbis)
{
    char frame[16];
    pvec->vt->fnClear((char *)pvec + pvec->vt->d0);
    CStackFrame_Construct(frame);
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    preq->cb = 4;
    preq->align = 0x10;
    void *pelem = PvAllocStackImpl__Fi(preq);
    int count = pbis->S32Read();
    CAry_Reserve(pvec->ary, count);
    if (count > 0) {
        for (; count != 0; count--) {
        memset(pelem, 0, 4);
        pvec->vt->fnRead((char *)pvec + pvec->vt->d1, pelem, pbis);
        pvec->vt->fnAdd((char *)pvec + pvec->vt->d2, pelem);
        }
    }
    CStackFrame_Destructor(frame, 2);
}
