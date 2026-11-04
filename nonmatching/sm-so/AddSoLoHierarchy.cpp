#include "sly2.h"
struct NODE;
struct NVT { char pad[0x58]; short delta; int (*fnUpdate)(void *); };
struct NODE { char pad[0xC]; NVT *vt; char pad2[0x24 - 0x10]; NODE *next; };
struct SOLO { char pad[0x40]; unsigned w40; char pad2[0x64 - 0x44]; NODE *phead; char pad3[0x70 - 0x68]; NODE *psentinel; char pad4[0xE8 - 0x74]; SOLO *pxr; };
struct U64P { unsigned long long v; } __attribute__((packed));
extern "C" {
void AddLoHierarchy(SOLO *);
void UpdateAloXfWorld(SOLO *);
void AddSoGeomsToOxa(SOLO *);
void QueueSwCallback(void *, SOLO *, unsigned long long, int);
QW PosLoWorld(void *);
void func_001F37C8(SOLO *, int);
int PpathzoneFindPos(QW, int);
extern char B_003DD490[];
extern char RO_002A8277[];
}

extern "C" void AddSoLoHierarchy(SOLO *pso)
{
    AddLoHierarchy(pso);
    UpdateAloXfWorld(pso);
    AddSoGeomsToOxa(pso);
    unsigned flags40 = pso->w40;
    if ((flags40 & 1) == 0) {
        unsigned *pflags = (unsigned *)flags40;
        *pflags = *pflags | 0x14;
    } else {
        pso->w40 = flags40 | 0x14;
    }
    SOLO *pxr = pso->pxr;
    int hasXr = 0;
    if (pxr != 0) {
        hasXr = *(int *)((char *)pxr + 0xDC);
    }
    NODE *pnode;
    if (hasXr != 0) {
        if (*(int *)(B_003DD490 + 0x45CC) != 0 && *(int *)0x2B002C != 0) {
            func_001F37C8(pso, PpathzoneFindPos(PosLoWorld(pso), 1));
            pnode = pso->phead;
        } else {
            QueueSwCallback(B_003DD490, pso, ((U64P *)RO_002A8277)->v, 0);
            pnode = pso->phead;
        }
    } else {
        pnode = pso->phead;
    }
    while (pnode != pso->psentinel) {
        NVT *pvt = pnode->vt;
        pvt->fnUpdate((char *)pnode + pvt->delta);
        pnode = pnode->next;
    }
}
