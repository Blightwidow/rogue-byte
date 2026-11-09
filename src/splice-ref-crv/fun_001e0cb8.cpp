// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
#define FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
s8 *PjsgeAllocJsg(int, int, int);
void func_001E0CB8(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, float value)
{
    s8 *record = PjsgeAllocJsg(arg0, 0x27, 0);
FIELD(record, int *, 0x10) = arg1;
FIELD(record, int *, 0x14) = arg2;
FIELD(record, int *, 0x18) = arg3;
FIELD(record, float *, 0x1C) = value;
FIELD(record, int *, 0x20) = arg4;
FIELD(record, int *, 0x24) = arg5;
}
}
