#include "sly2.h"
struct LO;
struct VT { char pad0[0x38]; short delta38; short index38; void (*fn38)(void *); char pad1[0x58 - 0x40]; short delta58; short index58; void (*fn58)(void *); char pad2[0xB8 - 0x60]; short deltaB8; short indexB8; void (*fnB8)(void *); };
struct LO { char pad0[0xC]; VT *vptr; int pa; int pad14; int oid; char pad1c[0xC]; unsigned long grfo; };
struct CLASSREC { char pad[0x10]; LO *(*pfnCreate)(); };
struct SWLOG { char pad[0x39E4]; LO **plog; };
extern "C" CLASSREC D_002BAAE8[];
extern "C" SWLOG B_003DD490;
extern "C" void *PframeFromSpliceBlock(SWLOG *, int, LO *);
extern "C" void CFramePtr_Assign(LO *, void *);
extern "C" void *PdlFromSwOid(SWLOG *, int);
extern "C" void *PdlFromSwCid(SWLOG *, int);
extern "C" void AppendSlEntry(void *, LO *);
extern "C" int FIsLoInWorld(LO *);

extern "C" LO *PloNew(int cid, int paloParent, int oid, int isplice)
{
    LO *plo = D_002BAAE8[cid].pfnCreate();
    plo->pa = paloParent;
    plo->oid = oid;
    CFramePtr_Assign(plo, PframeFromSpliceBlock(&B_003DD490, isplice, plo));
    AppendSlEntry(PdlFromSwOid(&B_003DD490, oid), plo);
    AppendSlEntry(PdlFromSwCid(&B_003DD490, cid), plo);
    VT *vt = plo->vptr;
    vt->fn38((char *)plo + vt->delta38);
    if (((int)(plo->grfo >> 60) & 1) != 0) {
        VT *vt2 = plo->vptr;
        vt2->fn58((char *)plo + vt2->delta58);
        //((char *)plo + vt->delta58);
    }
    if (FIsLoInWorld(plo) != 0) {
        VT *vt3 = plo->vptr;
        vt3->fnB8((char *)plo + vt3->deltaB8);
        //((char *)plo + vt->deltaB8);
    }
    LO **plog = B_003DD490.plog;
    if (plog != 0) {
        *plog = plo;
        B_003DD490.plog = plog + 1;
    }
    return plo;
}
