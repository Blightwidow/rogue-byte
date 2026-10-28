#include "sly2.h"
struct VEntry { short delta; short index; void *(*fn)(void *, int); };
struct ALO { char pad0[0xC]; VEntry *vptr; };
struct XF { char pad0[0xA8]; void *pxfMirror; };
struct XFMIRROR { XF *pxfSource; XF *pxfTarget; int fPosition; int fRotation; };
struct ALLOCREQ { int size; int align; };
extern char D_002C44F0;
extern "C" int S8Read__18CBinaryInputStream(void *);
extern "C" int S16Read__18CBinaryInputStream(void *);
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" void SetXfKind(ALO *, XF *, int);
extern "C" void LoadXfMirrors(ALO *palo, void *pbis)
{
    int count = S8Read__18CBinaryInputStream(pbis);
    if (count > 0) for (int cmirror = count; cmirror != 0; --cmirror) {
        ALLOCREQ req;
        req.size = 0x10;
        req.align = 0x10;
        XFMIRROR *pmirror = (XFMIRROR *)PvAllocSwClearImpl__Fi(&req);
        VEntry *entry = &palo->vptr[51];
        XF *pxfSource = (XF *)entry->fn((char *)palo + entry->delta, S16Read__18CBinaryInputStream(pbis));
        pmirror->pxfSource = pxfSource;
        if (pxfSource == 0)
            pmirror->pxfSource = (XF *)&D_002C44F0;
        entry = &palo->vptr[51];
        XF *pxfTarget = (XF *)entry->fn((char *)palo + entry->delta, S16Read__18CBinaryInputStream(pbis));
        pmirror->pxfTarget = pxfTarget;
        pmirror->fPosition = S8Read__18CBinaryInputStream(pbis);
        pmirror->fRotation = S8Read__18CBinaryInputStream(pbis);
        pmirror->pxfTarget->pxfMirror = pmirror;
        SetXfKind(palo, pmirror->pxfTarget, 0xF);
    }
}
