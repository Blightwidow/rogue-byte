#include "sly2.h"
struct VEntry { short delta; short index; void (*fn)(void *); };
struct LO { char pad0[0xC]; VEntry *vptr; char pad1[0x18]; unsigned long grfo; };
struct EXPLG { char pad[0xE0]; int cexpl; LO **apexpl; };
struct PLOARRAY { int a; int b; int cplo; LO **aplo; };
struct ALLOCREQ { int size; int align; };
extern "C" void LoadXfmFromBrx(EXPLG *, void *);
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void InitPloarray(PLOARRAY *);
extern "C" void LoadPloarrayFromBrx(EXPLG *, void *, PLOARRAY *);
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" int FIsBasicDerivedFrom(LO *, int);
void LoadExplgFromBrx(EXPLG *pexplg, void *pbis) __asm__("LoadExplgFromBrx");
void LoadExplgFromBrx(EXPLG *pexplg, void *pbis)
{
    char frame[16];
    PLOARRAY ploarray;
    ALLOCREQ req;
    LoadXfmFromBrx(pexplg, pbis);
    CStackFrame_Construct(frame);
    InitPloarray(&ploarray);
    LoadPloarrayFromBrx(pexplg, pbis, &ploarray);
    ALLOCREQ *preq = &req;
    preq->size = ploarray.cplo * 4;
    preq->align = 0x10;
    pexplg->apexpl = (LO **)PvAllocSwClearImpl__Fi(preq);
    for (int iplo = 0; iplo < ploarray.cplo; iplo++) {
        LO *plo = ploarray.aplo[iplo];
        plo->grfo |= 0x200000000000000UL;
        if (FIsBasicDerivedFrom(plo, 0x1E) == 0) {
            VEntry *entry = &plo->vptr[9];
            entry->fn((char *)plo + entry->delta);
        } else {
            int count = pexplg->cexpl;
            pexplg->apexpl[count] = plo;
            pexplg->cexpl = count + 1;
        }
    }
    CStackFrame_Destructor(frame, 2);
}
