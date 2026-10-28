#include "sly2.h"
struct LINK { char pad[0x10]; void *region; char pad2[0xC]; char sub[1]; };
struct PHYS { char pad[0xDC]; LINK *link; };
struct SO { char pad[0xE8]; PHYS *phys; };
struct REGION { char pad[0x118]; char dl[1]; };
struct DL;
int FFindDlEntry(void *, void *);
void RemoveDlEntry(void *, void *);
void AppendDlEntry(void *, void *);
void ResetPathzoneQuery(void *, void *);
void func_001F37C8(SO *so, REGION *region)
{
    LINK *link = so->phys->link;
    REGION *old = (REGION *)link->region;
    if (old == region) return;
    if (old) {
        if (FFindDlEntry(old->dl, link))
            RemoveDlEntry(old->dl, link);
    }
    if (region) {
        if (FFindDlEntry(region->dl, link)) {
            link->region = region;
            return;
        }
        AppendDlEntry(region->dl, link);
        ResetPathzoneQuery(region, link->sub);
    }
    link->region = region;
}
