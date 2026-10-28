#include "sly2.h"
struct CBinaryInputStream { int pad; unsigned U16Read(); unsigned U32Read(); };
struct BSPNODE { unsigned pbspNeg; unsigned pbspPos; unsigned psurf; };
struct BSPC { int cbsp; int unk4; int unk8; BSPNODE *absp; };
struct GEOM { char pad[0xC]; char *psurf; };
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
extern "C" char D_002BBAF0;

void CBinaryInputStream_ReadBspc(CBinaryInputStream *pbis, GEOM *pgeom, BSPC *pbspc)
{
    pbspc->cbsp = pbis->U32Read();
    pbspc->unk4 = pbis->U32Read();
    pbspc->unk8 = pbis->U32Read();
    ALLOCREQ allocreq;
    allocreq.cb = pbspc->cbsp * 0xC;
    allocreq.cbAlign = 0x10;
    pbspc->absp = (BSPNODE *)PvAllocSwClearImpl__Fi(&allocreq);
    for (int ibsp = 0; ibsp < pbspc->cbsp; ibsp++) {
        BSPNODE *pbsp = &pbspc->absp[ibsp];
        unsigned isurf = pbis->U16Read();
        if (isurf == 0xFFFF) {
            pbsp->psurf = (unsigned)&D_002BBAF0;
            continue;
        }
        pbsp->psurf = (unsigned)(pgeom->psurf + isurf * 0x20);
        unsigned ibspNeg = pbis->U32Read();
        if (ibspNeg != 0xFFFFFFFFu)
            pbsp->pbspNeg = (unsigned)(pbspc->absp + ibspNeg);
        unsigned ibspPos = pbis->U32Read();
        if (ibspPos != 0xFFFFFFFFu)
            pbsp->pbspPos = (unsigned)(pbspc->absp + ibspPos);
    }
}
