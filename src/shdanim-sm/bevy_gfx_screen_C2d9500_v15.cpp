// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Vt1EF8C8 {
    char pad0[0xE8];
    short delta;
    short index;
    void (*fn)(void *, QW);
};
struct Obj1EF8C8 {
    char pad0[0xC];
    Vt1EF8C8 *vptr;
    char pad1[0x140];
    int flag150;
};
extern "C" {
void UpdateSo();
QW PosLoWorld(void *);
struct Block1EF8C8 { QW lanes[4]; };
extern Block1EF8C8 g_2ddfa0;
}
// lane 2 (pextuw with $zero) of a QW to an FP register
static inline float Lane2(QW q) { float f; int t; asm("pextuw %1, $0, %2\n\tmtc1 %1, %0" : "=f" (f), "=&r" (t) : "r" (q)); return f; }
extern "C" void bevy_gfx_screen_C2d9500_v15(Obj1EF8C8 *object)
{
    UpdateSo();
    QW vec = g_2ddfa0.lanes[3];
    if (object->flag150 == 0) {
        QW pos = PosLoWorld(object);
        ((float *)&vec)[2] = Lane2(pos);
    }
    object->vptr->fn((char *)object + object->vptr->delta, vec);
}
