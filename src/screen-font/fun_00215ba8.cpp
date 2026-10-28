#include "sly2.h"
struct MT { int a; int pad4; int cur; int base; int other; char pad14[4]; int rgba; char pad1c[0x24]; QW r0; QW r1; char pad60[4]; float ox; float oy; int z6c; int z70; float f74; float f78; float f7c; float f80; float f84; float f88; int i8c; int i90; int i94; };
struct SRC { char pad[8]; char *owner; char pad2[0x10]; int i1c; float f20; float f24; float f28; int i2c; int i30; };
struct M3 { QW r[3]; };
extern char B_003DD490[];
extern "C" void CMovieText_Reset(MT *, int);

MT *func_00215BA8(MT *t, int a, SRC *s, char *slot)
{
    char *gl = B_003DD490;
    M3 m = *(M3 *)slot;
    t->a = a;
    t->z6c = 0;
    t->z70 = 0;
    t->f74 = s->f24;
    t->f78 = s->f28;
    t->f7c = 1.0f;
    t->f80 = 1.0f;
    t->i90 = s->i2c;
    t->i8c = s->i30;
    t->ox = *(float *)(*(char **)(s->owner + 0xC8) + 0x9C);
    t->oy = *(float *)(*(char **)(s->owner + 0xC8) + 0xA0);
    t->i94 = *(int *)(s->owner + 0xA4);
    float g = s->f20;
    t->f84 = g;
    t->f88 = g * 0.01953125f;
    int pf = *(int *)(*(char **)(gl + 0x3BE8) + 0x54);
    t->base = pf;
    t->cur = pf;
    t->other = *(int *)(*(char **)(gl + 0x3BE8) + 0x54) + 0x40;
    t->rgba = s->i1c;
    t->r0 = m.r[1];
    t->r1 = m.r[2];
    CMovieText_Reset(t, 0);
    return t;
}
