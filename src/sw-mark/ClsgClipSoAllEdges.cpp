#include "sly2.h"
struct LSG { char pad[0x54]; void *pedge; char pad2[0x60 - 0x58]; };
struct EDGE { unsigned short ipos0; unsigned short ipos1; int pad[3]; };
struct SOGEOM { char pad[0x94]; QW *apos; int unk98; int unk9c; int cedge; EDGE *aedge; };
struct SW; struct BSP;
extern "C" int ClsgClipEdgeToBsp(BSP *, int, QW, QW, int, LSG *);
int ClsgClipSoAllEdges(SW *psw, SOGEOM *pgeomOther, SOGEOM *pgeom, BSP *pbsp, int clsgMax, LSG *alsg) {
    int ilsgNew = 0;
    int clsg = 0;
    QW *apos = pgeom->apos;
    EDGE *aedge = pgeom->aedge;
    int iedge = pgeom->cedge;
    while (--iedge >= 0) {
        EDGE *pedge = &aedge[iedge];
        clsg += ClsgClipEdgeToBsp(pbsp, 0x7FFFFFFF, apos[pedge->ipos0], apos[pedge->ipos1], clsgMax - clsg, &alsg[clsg]);
        while (ilsgNew < clsg) {
            alsg[ilsgNew].pedge = pedge;
            ilsgNew++;
        }
    }
    return clsg;
}
