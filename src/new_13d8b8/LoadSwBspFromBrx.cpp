#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct BSPNODE { char vec[16]; BSPNODE *pnodeFront; BSPNODE *pnodeBack; int iregionFront; int iregionBack; };
struct SW { char pad[0x4558]; int cnode; BSPNODE *anode; int cregion; void *aregion; };
struct Bis;
extern "C" unsigned U16Read__18CBinaryInputStream(Bis *);
extern "C" int S16Read__18CBinaryInputStream(Bis *);
extern "C" void CBinaryInputStream_ReadVector4(Bis *, void *);
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);

extern "C" void LoadSwBspFromBrx(SW *psw, Bis *pbis)
{
    int cnode = U16Read__18CBinaryInputStream(pbis);
    ALLOCREQ allocreq;
    allocreq.cb = cnode << 5;
    allocreq.cbAlign = 0x10;
    psw->cnode = cnode;
    psw->anode = (BSPNODE *)PvAllocSwClearImpl__Fi(&allocreq);
    psw->cregion = 0;
    for (int inode = 0; inode < psw->cnode; inode++) {
        BSPNODE *pnode = &psw->anode[inode];
        CBinaryInputStream_ReadVector4(pbis, pnode);
        int inodeFront = S16Read__18CBinaryInputStream(pbis);
        if (inodeFront >= 0) {
            pnode->pnodeFront = &psw->anode[inodeFront];
        } else {
            pnode->iregionFront = psw->cregion++;
        }
        int inodeBack = S16Read__18CBinaryInputStream(pbis);
        if (inodeBack >= 0) {
            pnode->pnodeBack = &psw->anode[inodeBack];
        } else {
            pnode->iregionBack = psw->cregion++;
        }
    }
    allocreq.cbAlign = 0x10;
    allocreq.cb = psw->cregion << 5;
    psw->aregion = PvAllocSwClearImpl__Fi(&allocreq);
}
