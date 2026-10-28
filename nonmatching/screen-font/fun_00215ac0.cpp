#include "sly2.h"
struct MT { int a; int pad4; int cur; int base; int other; char pad14[4]; int rgba; char pad1c[0x24]; QW r0; QW r1; char pad60[4]; float ox; float oy; int z6c; int z70; int z74; int z78; float f7c; float f80; float f84; float f88; int i8c; int i90; int i94; };
extern char B_003DD490[];
extern "C" QW g_2a2e10;
extern "C" QW g_2a2e20;
extern "C" void CMovieText_Reset(MT *, int);
MT *func_00215AC0(MT *t, int a, float scale)
{
    t->a = a;
    t->f80 = 1.0f;
    t->ox = 1792.0f;
    t->oy = 1936.0f;
    t->f84 = scale * 51.2f;
    t->f7c = 1.0f;
    t->f88 = scale;
    t->i8c = 1;
    t->i94 = 6;
    t->z6c = 0;
    t->z70 = 0;
    t->z74 = 0;
    t->z78 = 0;
    t->i90 = 1;
    int pf = *(int *)(*(char **)(B_003DD490 + 0x3BE8) + 0x54);
    t->base = pf;
    t->cur = pf;
    t->rgba = 0x80808080;
    t->other = *(int *)(*(char **)(B_003DD490 + 0x3BE8) + 0x54) + 0x40;
    t->r0 = g_2a2e10;
    t->r1 = g_2a2e20;
    CMovieText_Reset(t, 0);
    return t;
}
