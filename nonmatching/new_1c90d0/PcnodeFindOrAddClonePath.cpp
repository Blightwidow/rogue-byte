#include "sly2.h"
struct CNODE { int cloneid; CNODE *parent; int oid; char pad[0x14 - 0xC]; CNODE *next; CNODE *first; char pad2[0x28 - 0x1C]; };
struct ALLOCREQ { int cb; int align; };
extern "C" {
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void InitSl(void *, int);
int OidFromCloneId(int);
void *func_0015E3C0(void *, int);
void AppendSlEntry(void *, void *);
extern char B_003DD490[];
}
CNODE *PcnodeFindOrAddClonePath(CNODE *pparent, int count, const int *acloneid)
{
    CNODE *pnode;
again:
    pnode = pparent->first;
    if (pnode != 0) {
        while (pnode->cloneid != acloneid[0]) {
            pnode = pnode->next;
            if (pnode == 0)
                goto create;
        }
        pparent = pnode;
        if (count == 1)
            return pnode;
        count = count - 1;
        acloneid = acloneid + 1;
        goto again;
    }
create:
    ALLOCREQ req;
    req.cb = count * 0x28;
    req.align = 0x10;
    CNODE *pnodes = (CNODE *)PvAllocSwClearImpl__Fi(&req);
    CNODE *plast = pparent;
    pnode = 0;
    for (int index = 0; index < count; index++) {
        pnode = &pnodes[index];
        InitSl(&pnode->first, 0x14);
        int cloneid = *acloneid++;
        pnode->cloneid = cloneid;
        pnode->oid = OidFromCloneId(cloneid);
        AppendSlEntry(func_0015E3C0(B_003DD490, pnode->oid), pnode);
        pnode->parent = plast;
        AppendSlEntry(&plast->first, pnode);
        plast = pnode;
    }
    return pnode;
}
