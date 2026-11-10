#include "sly2.h"
#include "sw.h"
struct VTSINK { char pad[8]; short delta; short index; void (*fn)(void *, int, void *); };
struct SINK { VTSINK *vt; };
struct CLONESET { int cpalo; LO **apalo; char pad0[4]; int icloneFree; char pad1[8]; int *aoidClone; char pad2[0x6C - 0x1C]; };
extern "C" unsigned MakeCloneId(int, int);

void InstantiateClone(SW *sw, int iset, LO *parent, void *pxf, int oid, void *pmat, SINK *sink)
{
    CLONESET *set = sw->acloneset + iset;
    unsigned cloneid = MakeCloneId(iset, set->icloneFree);
    set->aoidClone[set->icloneFree] = oid;
    int index = 0;
    while (index < set->cpalo) {
        LO *lo = set->apalo[set->icloneFree * set->cpalo + index];
        index++;
        lo->SetCloneId(cloneid, 1);
        lo->Add();
        lo->SetParent(parent, pxf, 0);
        lo->Slot37(pmat);
    }
    if (sink) {
        sink->vt->fn((char *)sink + sink->vt->delta, set->cpalo, set->apalo + set->icloneFree * set->cpalo);
    }
    set->icloneFree = set->icloneFree + 1;
}
