#include "sly2.h"
struct Bis;
struct VT { short delta; short index; void *(*fn)(void *, int); };
struct ALO { char pad0[0xC]; char *vt; };
struct XF { char pad0[0xA8]; void *pxfMirror; };
struct XFMIRROR { XF *pxfSource; XF *pxfTarget; int fPosition; int fRotation; };
struct ALLOCREQ { int cb; int cbAlign; };
extern char D_002C44F0;
extern "C" int S8Read__18CBinaryInputStream(Bis *);
extern "C" int S16Read__18CBinaryInputStream(Bis *);
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" void SetXfKind(ALO *, XF *, int);
static inline XF *ReadXf(ALO *palo, Bis *pbis)
{
    VT *vt = (VT *)(palo->vt + 0x198);
    return (XF *)vt->fn((char *)palo + vt->delta, S16Read__18CBinaryInputStream(pbis));
}
extern "C" void LoadXfMirrors(ALO *palo, Bis *pbis)
{
    int count = S8Read__18CBinaryInputStream(pbis);
    if (count > 0) for (int cmirror = count; cmirror != 0; --cmirror) {
        ALLOCREQ req;
        req.cb = 0x10;
        req.cbAlign = 0x10;
        XFMIRROR *pmirror = (XFMIRROR *)PvAllocSwClearImpl__Fi(&req);
        pmirror->pxfSource = ReadXf(palo, pbis);
        if (pmirror->pxfSource == 0)
            pmirror->pxfSource = (XF *)&D_002C44F0;
        pmirror->pxfTarget = ReadXf(palo, pbis);
        pmirror->fPosition = S8Read__18CBinaryInputStream(pbis);
        pmirror->fRotation = S8Read__18CBinaryInputStream(pbis);
        pmirror->pxfTarget->pxfMirror = pmirror;
        SetXfKind(palo, pmirror->pxfTarget, 0xF);
    }
}
