// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct NODE;
struct BASIC {
    char pad[0xC];
    virtual void Virtual0();
    virtual void Virtual1();
    virtual void Virtual2();
    virtual void Virtual3();
    virtual void Virtual4();
    virtual void Virtual5();
    virtual void Virtual6();
    virtual void Virtual7();
    virtual void Virtual8();
    virtual void Virtual9();
    virtual void Update();
};
struct NODE : BASIC {
    char pad2[0x24 - 0x10];
    NODE *next;
};
struct SOLO { char pad[0x40]; unsigned w40; char pad2[0x64 - 0x44]; NODE *phead; char pad3[0x70 - 0x68]; NODE *psentinel; char pad4[0xE8 - 0x74]; SOLO *pxr; };
struct PZGRAPH { char pad[0x2C]; int field2C; };
struct SW { char pad[0x45CC]; PZGRAPH *ppzgraph; };
struct UL { unsigned long v; } __attribute__((packed));
extern "C" {
void AddLoHierarchy(SOLO *);
void UpdateAloXfWorld(SOLO *);
void AddSoGeomsToOxa(SOLO *);
void QueueSwCallback(SW *, SOLO *, unsigned long, int);
QW PosLoWorld(void *);
void func_001F37C8(SOLO *, int);
int PpathzoneFindPos(QW, int);
extern SW B_003DD490;
extern const UL RO_002A8270;
}

static inline int FIsInline(unsigned flags)
{
    return (flags & 1) == 0;
}

extern "C" void AddSoLoHierarchy(SOLO *pso)
{
    VECTOR vector;
    AddLoHierarchy(pso);
    UpdateAloXfWorld(pso);
    AddSoGeomsToOxa(pso);
    unsigned flags40 = pso->w40;
    if (FIsInline(flags40)) {
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
    if (hasXr != 0) {
        PZGRAPH *pgraph = B_003DD490.ppzgraph;
        if (pgraph != 0 && pgraph->field2C != 0) {
            func_001F37C8(pso, PpathzoneFindPos(PosLoWorld(pso), 1));
        } else {
            QueueSwCallback(&B_003DD490, pso, RO_002A8270.v, 0);
        }
    }
    for (NODE *pnode = pso->phead; pnode != pso->psentinel; pnode = pnode->next) {
        pnode->Update();
    }
}
