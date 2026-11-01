// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LIST1D2420 { char pad0[0xE8]; int count; char pad1[0xF4 - 0xEC]; char *array; };
struct OBJ1D2420 { char pad[0x5AC]; LIST1D2420 *list; int flag; };
extern "C" {
QW PosLoWorld(OBJ1D2420 *);
void func_001D2420(OBJ1D2420 *obj)
{
    obj->flag = 0;
    QW pos = PosLoWorld(obj);
    QW upper;
    asm("pextuw %0, $0, %1" : "=r"(upper) : "r"(pos));
    float z;
    asm("mtc1 %1, %0" : "=f"(z) : "r"(upper));
    for (int index = 0; index < obj->list->count; index++)
        *(float *)(obj->list->array + index * 16 + 8) = z;
}
}
