// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "alloc.h"
#include "vu0inline.h"
#include "ps2inline.h"
static inline ALLOCREQ *Aligned(ALLOCREQ *request)
{
    request->cbAlign = 0x10;
    return request;
}
struct SOGEOMLVO { int *aedge; int *aedge2; int *atri; };
struct SOGEOMX {
    char pad0[0x10];
    SOGEOMLVO *plvo;
    char pad14[0x68];
    QW *apos;
    char pad80[4];
    QW *anormal;
    char pad88[8];
    int cpos;
    char pad94[4];
    int ctri;
    char pad9c[4];
    int cpoly;
    char *apoly;
};
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
}
extern "C" void EnsureSogeomLvo(SOGEOMX *psogeom)
{
    QW edge1[1];
    QW edge2[1];
    QW normal[1];
    char frame[0x10];
    ALLOCREQ req;
    if (psogeom->plvo != 0)
        return;
    CStackFrame_Construct(frame);
    req.cb = 0xC;
    psogeom->plvo = (SOGEOMLVO *)PvAllocSwImpl__Fi(Aligned(&req));
    req.cb = psogeom->cpos << 4;
    psogeom->plvo->aedge = (int *)PvAllocSwClearImpl__Fi(Aligned(&req));
    req.cb = psogeom->cpos << 4;
    psogeom->plvo->aedge2 = (int *)PvAllocSwClearImpl__Fi(Aligned(&req));
    req.cb = psogeom->ctri * 0xC;
    psogeom->plvo->atri = (int *)PvAllocSwClearImpl__Fi(Aligned(&req));
    req.cb = psogeom->ctri << 2;
    int *acount = (int *)PvAllocStackClearImpl__Fi(Aligned(&req));
    for (int ipoly = 0; ipoly < psogeom->cpoly; ipoly++) {
        unsigned short *pindex = (unsigned short *)(psogeom->apoly + ipoly * 0x10);
        unsigned short *ppair = pindex + 2;
        for (int ipair = 0; ipair < 2; ipair++) {
            unsigned int itri = ppair[ipair];
            int *atri = psogeom->plvo->atri + itri * 3;
            int ifound;
            for (int ivertex = 0; ivertex < 2; ivertex++) {
                unsigned int vertex = pindex[ivertex];
                for (ifound = 0; ifound < acount[itri]; ifound++)
                    if (vertex == atri[ifound])
                        break;
                if (ifound >= acount[itri] && ifound < 3) {
                    atri[acount[itri]] = vertex;
                    acount[itri] += 1;
                }
            }
        }
    }
    QW *apos = psogeom->apos;
    for (int itri = 0; itri < psogeom->ctri; itri++) {
        int *ptri = psogeom->plvo->atri + itri * 3;
        edge1[0] = VectorSub(apos[ptri[1]], apos[ptri[0]]);
        edge2[0] = VectorSub(apos[ptri[2]], apos[ptri[0]]);
        normal[0] = CrossProduct(edge1[0], edge2[0]);
        QW dot = DotProduct(normal[0], psogeom->anormal[itri * 2]);
        if (LaneX(dot) < 0.0f) {
            int swap = ptri[1];
            ptri[1] = ptri[2];
            ptri[2] = swap;
        }
    }
    CStackFrame_Destructor(frame, 2);
}
