#include "sly2.h"
extern "C" {
struct Node { int kind; int oid; void *plo; };
struct Crv { char pad[0xE8]; int cnode; char pad2[8]; QW *apos; };
struct Path { char pad[0x54]; int cnode; Node *anode; Crv *pcrv; };
extern char B_003DD490;
void PostLoLoad(Path *);
Crv *PcrvNew(int, int);
void *PloFindSwObject_thunk(char *, int, int, Path *);
QW PosLoWorld(void *);
void MeasureCrv(Crv *);
}

void func_0014A0A8(Path *ppath)
{
    int inode = 0;
    PostLoLoad(ppath);
    Crv *pcrv = PcrvNew(0x62C, ppath->cnode);
    ppath->pcrv = pcrv;
    pcrv->cnode = ppath->cnode;
    for (; inode < ppath->cnode; inode++) {
        Node *pnode = &ppath->anode[inode];
        void *plo = PloFindSwObject_thunk(&B_003DD490, 4, pnode->oid, ppath);
        pnode->plo = plo;
        if (plo) {
            QW *dest = (QW *)((inode << 4) + (int)ppath->pcrv->apos);
            *dest = PosLoWorld(plo);
        }
    }
    MeasureCrv(ppath->pcrv);
}
