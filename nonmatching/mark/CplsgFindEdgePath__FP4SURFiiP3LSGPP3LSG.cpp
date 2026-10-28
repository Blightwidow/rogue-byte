struct SURF { char pad[0x18]; unsigned grf; char pad2[0x20 - 0x1C]; };
struct EDGE { char pad[4]; unsigned short isurf0; unsigned short isurf1; };
struct LSG { char pad[0x54]; EDGE *pedge; char pad2[4]; LSG *plsgNext; };
struct FEP { FEP *pfepSource; LSG *plsg; int isurf; };
int CplsgFindEdgePath(SURF *asurf, int isurf, int isurfTarget, LSG *plsgEdge, LSG **aplsg) {
    FEP afep[64];
    int cfep = 1;
    int cplsg;
    afep[0].pfepSource = 0;
    afep[0].isurf = isurf;
    afep[0].plsg = 0;
    for (int ifep = 0; ifep < cfep; ifep++) {
        FEP *pfep = &afep[ifep];
        for (LSG *plsg = plsgEdge; plsg != 0; plsg = plsg->plsgNext) {
            EDGE *pedge = plsg->pedge;
            int isurfNext;
            if (pedge->isurf0 == pfep->isurf)
                isurfNext = pedge->isurf1;
            else if (pedge->isurf1 == pfep->isurf)
                isurfNext = pedge->isurf0;
            else
                continue;
            if (isurfNext == isurfTarget) {
                aplsg[0] = plsg;
                cplsg = 1;
                for (FEP *pfepPath = pfep; pfepPath->plsg != 0; pfepPath = pfepPath->pfepSource)
                    aplsg[cplsg++] = pfepPath->plsg;
                goto done;
            }
            if ((asurf[isurfNext].grf & 4) == 0) {
                asurf[isurfNext].grf |= 4;
                afep[cfep].pfepSource = pfep;
                afep[cfep].plsg = plsg;
                afep[cfep].isurf = isurfNext;
                cfep++;
            }
        }
    }
    cplsg = 0;
done:
    for (int ifepClear = 0; ifepClear < cfep; ifepClear++)
        asurf[afep[ifepClear].isurf].grf &= ~4u;
    return cplsg;
}
