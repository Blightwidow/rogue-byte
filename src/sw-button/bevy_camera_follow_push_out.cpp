// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "alloc.h"
#include "vu0inline.h"
struct SW { char pad[0x3D1C]; struct BVNODE *pbvnode; };
struct GEOM { char pad[0x60]; GEOM *pgeomNext; };
struct BVNODE { float lo[3]; float pad0; float hi[3]; char pad1[0x18]; GEOM *pgeom; char pad2[8]; BVNODE *pnext; };
union BOXES { QW q[2]; float f[8]; };
extern "C" {
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void UpdateSwAaox__FP2SW(SW *);
void func_00133E30(SW *);
void bevy_camera_follow_push_out(SW *psw, QW posA, QW posB, int (*pfn)(void *, void *), void *pvArg, int *pcount, GEOM ***plist)
{
    BOXES box;
    ALLOCREQ req;
    QW lo = VectorMiniXyz(posA, posB);
    QW hi = VectorMaxXyz(posA, posB);
    int count = 0;
    box.q[0] = lo;
    box.q[1] = hi;
    ALLOCREQ *preq = &req;
    int align = 0x10;
    req.cb = 0x400;
    preq->cbAlign = align;
    GEOM **list = (GEOM **)PvAllocStackImpl__Fi(preq);
    func_00133E30(psw);
    UpdateSwAaox__FP2SW(psw);
    for (BVNODE *pnode = psw->pbvnode; pnode; pnode = pnode->pnext) {
        if (pnode->lo[0] > box.f[4] || pnode->hi[0] < box.f[0] || pnode->lo[1] > box.f[5] || pnode->hi[1] < box.f[1] || pnode->lo[2] > box.f[6] || pnode->hi[2] < box.f[2])
            continue;
        GEOM *pgeom = pnode->pgeom;
        if (!pgeom) continue;
        GEOM **pslot = (GEOM **)(count * 4 + (int)list);
        do {
            if ((!pfn || pfn(pvArg, pgeom)) && count < 0x100) {
                *pslot++ = pgeom;
                count++;
            }
            pgeom = pgeom->pgeomNext;
        } while (pgeom);
    }
    *plist = list;
    *pcount = count;
}
}
