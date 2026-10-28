#include "sly2.h"
struct VTE { short delta; short index; void *fn; };
struct LO;
struct VTLO { char pad0[0x40]; VTE addLo; char pad1[0x50 - 0x48]; VTE setParent; char pad2[0xC8 - 0x58]; VTE setCloneId; char pad3[0x128 - 0xD0]; VTE transform; };
struct LO { char pad[0xC]; VTLO *vt; };
struct VTSINK { char pad[8]; short delta; short index; void (*fn)(void *, int, void *); };
struct SINK { VTSINK *vt; };
struct CLONESET { int cpalo; LO **apalo; char pad0[4]; int icloneFree; char pad1[8]; int *aoidClone; char pad2[0x6C - 0x1C]; };
struct SW { char pad[0x3F08]; CLONESET *acloneSet; };
extern "C" unsigned MakeCloneId(int, int);

void InstantiateClone(SW *sw, int iset, void *parent, void *pxf, int oid, void *pmat, SINK *sink)
{
    CLONESET *set = sw->acloneSet + iset;
    unsigned cloneid = MakeCloneId(iset, set->icloneFree);
    set->aoidClone[set->icloneFree] = oid;
    int index = 0;
    while (index < set->cpalo) {
        LO *lo = set->apalo[set->icloneFree * set->cpalo + index];
        index++;
        ((void (*)(void *, unsigned, int))lo->vt->setCloneId.fn)((char *)lo + lo->vt->setCloneId.delta, cloneid, 1);
        ((void (*)(void *))lo->vt->addLo.fn)((char *)lo + lo->vt->addLo.delta);
        ((void (*)(void *, void *, void *, int))lo->vt->setParent.fn)((char *)lo + lo->vt->setParent.delta, parent, pxf, 0);
        ((void (*)(void *, void *))lo->vt->transform.fn)((char *)lo + lo->vt->transform.delta, pmat);
    }
    if (sink) {
        sink->vt->fn((char *)sink + sink->vt->delta, set->cpalo, set->apalo + set->icloneFree * set->cpalo);
    }
    set->icloneFree = set->icloneFree + 1;
}
