// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LIST1D2420 { char pad0[0xE8]; int count; char pad1[0xF4 - 0xEC]; char *array; };
struct OBJ1D2420 { char pad[0x5AC]; LIST1D2420 *list; int flag; };
// lane 2 (z) of a 128-bit vector into a float register
static inline float Lane2_1D2420(QW q)
{
    QW upper;
    float f;
    asm("pextuw %0, $0, %1" : "=r"(upper) : "r"(q));
    asm("mtc1 %1, %0" : "=f"(f) : "r"(upper));
    return f;
}
extern "C" {
QW PosLoWorld(OBJ1D2420 *);
void func_001D2420(OBJ1D2420 *obj)
{
    obj->flag = 0;
    QW pos = PosLoWorld(obj);
    for (int index = 0; index < obj->list->count; index++)
        *(float *)(obj->list->array + index * 16 + 8) = Lane2_1D2420(pos);
}
}
