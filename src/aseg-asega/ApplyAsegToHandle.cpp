#include "sly2.h"
struct ASEGA;
struct ASEGAVT { char pad[8]; short delta; short index; void (*fn)(void *); };
struct ASEGA { char pad[0xC]; ASEGAVT *vptr; };
struct ASEG;
extern "C" void RetractAsegaHandle(ASEGA **);
extern "C" void ApplyAseg(ASEG *, int, float, float, int, ASEGA **);

extern "C" void ApplyAsegToHandle(ASEG *paseg, int paloRoot, int grfapl, ASEGA **handle, float tLocal, float svtLocal)
{
    RetractAsegaHandle(handle);
    if (paseg != 0) {
        ApplyAseg(paseg, paloRoot, tLocal, svtLocal, grfapl, handle);
        ASEGA *pasega = *handle;
        ASEGAVT *vtable = pasega->vptr;
        vtable->fn((char *)pasega + vtable->delta);
    }
}
