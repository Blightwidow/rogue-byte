// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct BND { float x, y, z, r, a, b; };
struct GS {
    char pad0[0x10];
    VECTOR center;
    float radius;
    char pad1[0x44 - 0x24 - 0];
    BND *abnd;
};
struct ALO { char pad[0x148]; unsigned long grf; };
struct GLOBSET { ALO *palo; char pad[0xC]; VECTOR center; float radius; char pad2[0x20]; BND *abnd; };
extern "C" void RemoveAloFromRenderTree(ALO *);
extern "C" float func_002599D8(VECTOR *);
extern "C" float func_002599E0(VECTOR *);
extern "C" float func_002599E8(VECTOR *);
extern "C" VECTOR g_2a2dd0;
void func_0016EF00(GLOBSET *g, int index)
{
    RemoveAloFromRenderTree(g->palo);
    g->palo->grf &= ~0x800000000UL;
    g->center = g_2a2dd0;
    g->radius = 1000000.0f;
    BND *b = g->abnd + index;
    VECTOR v = g_2a2dd0;
    float x = func_002599D8(&v);
    float y = func_002599E0(&v);
    float z = func_002599E8(&v);
    b->r = 1000000.0f;
    b->x = x; b->y = y; b->z = z;
}
