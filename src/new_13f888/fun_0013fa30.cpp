#include "sly2.h"
struct VT { short delta; short index; void (*fn)(void *, int, int); };
struct LO { char pad[0xC]; VT *vt; };
struct PLOSINK { int unk0; int nLayer; int nParam; };
extern "C" void func_001A58D0(LO *, int, int);
extern "C" void func_0013F990(LO *, int);
void AddPlosToSink(PLOSINK *psink, int cplo, LO **aplo)
{
    if (cplo > 0) {
        LO **pp = aplo;
        int n = cplo;
        do {
            LO *plo = *pp;
            func_001A58D0(plo, 0, 0);
            func_0013F990(plo, psink->nLayer);
            if (psink->nParam != -1) {
                VT *slot = (VT *)((char *)plo->vt + 0xC8);
                slot->fn((char *)plo + slot->delta, psink->nParam, 1);
            }
            pp++;
        } while (--n != 0);
    }
}
