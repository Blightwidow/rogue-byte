// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "so.h"
#include "sw.h"
struct PZGRAPH { char pad[0x2C]; int field2C; };
struct UL { unsigned long v; } __attribute__((packed));
extern "C" {
void AddLoHierarchy(SO *);
void UpdateAloXfWorld(SO *);
void AddSoGeomsToOxa(SO *);
void QueueSwCallback(SW *, SO *, unsigned long, int);
QW PosLoWorld(void *);
void func_001F37C8(SO *, int);
int PpathzoneFindPos(QW, int);
extern SW B_003DD490;
extern const UL RO_002A8270;
}

static inline int FIsInline(unsigned flags)
{
    return (flags & 1) == 0;
}

extern "C" void AddSoLoHierarchy(SO *pso)
{
    VECTOR vector;
    AddLoHierarchy(pso);
    UpdateAloXfWorld(pso);
    AddSoGeomsToOxa(pso);
    u32 grf = pso->grfSw;
    if (FIsInline(grf)) {
        pso->pgrfentry->grf |= 0x14;
    } else {
        pso->grfSw = grf | 0x14;
    }
    PHYS *pphys = pso->pphys;
    int hasXr = 0;
    if (pphys != 0) {
        hasXr = *(int *)((char *)pphys + 0xDC);
    }
    if (hasXr != 0) {
        PZGRAPH *pgraph = B_003DD490.ppzgraph;
        if (pgraph != 0 && pgraph->field2C != 0) {
            func_001F37C8(pso, PpathzoneFindPos(PosLoWorld(pso), 1));
        } else {
            QueueSwCallback(&B_003DD490, pso, RO_002A8270.v, 0);
        }
    }
    for (LO *plo = (LO *)pso->dlChild.head; plo != pso->ploChildEnd; plo = plo->ploNext) {
        plo->AddHierarchy();
    }
}
