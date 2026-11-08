// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

struct SL { void *pvFirst; void *pvLast; int ibSle; };
struct CNODE {
    int cloneid;
    CNODE *pcnodeParent;
    int oid;
    int field0C;
    CNODE *field10;
    CNODE *pcnodeNext;
    SL slChild;
    int field24;
};
struct ALLOCREQ { int cb; int align; };

extern "C" {
void *PvAllocSwClearImpl__Fi(ALLOCREQ *preq);
void InitSl(SL *psl, int ibSle);
int OidFromCloneId(int cloneid);
SL *func_0015E3C0(void *ptable, int oid);
void AppendSlEntry(SL *psl, void *pv);
extern char B_003DD490[];
}

// Retail walks the child list with acloneid and count in their incoming
// registers, then in the allocation loop keeps a fresh down-counter and a
// fresh pointer for the clone ids ($s2, $s3). That second pointer is the
// strength-reduced giv of acloneid[index]: reading the id as *acloneid++
// reuses $s2 and drops the copy. The allocator takes only the request
// (PvAllocSwClearImpl__Fi, one argument in its own callers in src/).
CNODE *PcnodeFindOrAddClonePath(CNODE *pcnodeParent, int count, const int *acloneid)
{
    CNODE *pcnode;
again:
    pcnode = (CNODE *)pcnodeParent->slChild.pvFirst;
    while (pcnode != 0) {
        if (pcnode->cloneid == acloneid[0]) {
            pcnodeParent = pcnode;
            if (count == 1)
                return pcnode;
            count = count - 1;
            acloneid = acloneid + 1;
            goto again;
        }
        pcnode = pcnode->pcnodeNext;
    }
    ALLOCREQ req;
    req.cb = count * sizeof(CNODE);
    req.align = 0x10;
    CNODE *acnode = (CNODE *)PvAllocSwClearImpl__Fi(&req);
    CNODE *pcnodeLast = pcnodeParent;
    for (int index = 0; index < count; index++) {
        pcnode = &acnode[index];
        InitSl(&pcnode->slChild, 0x14);
        int cloneid = acloneid[index];
        pcnode->cloneid = cloneid;
        pcnode->oid = OidFromCloneId(cloneid);
        AppendSlEntry(func_0015E3C0(B_003DD490, pcnode->oid), pcnode);
        pcnode->pcnodeParent = pcnodeLast;
        AppendSlEntry(&pcnodeLast->slChild, pcnode);
        pcnodeLast = pcnode;
    }
    return pcnode;
}
