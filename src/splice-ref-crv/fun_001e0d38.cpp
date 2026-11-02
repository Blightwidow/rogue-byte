// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8;
#define FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
s8 *PjsgeAllocJsg(int, int, int);
void func_001E0D38(int arg0, int arg1, float value0, int arg2, float value1, int arg3, int arg4)
{
    s8 *record = PjsgeAllocJsg(arg0, 0x28, 0);
    FIELD(record, int *, 0x10) = arg1;
    FIELD(record, float *, 0x14) = value0;
    FIELD(record, int *, 0x18) = arg2;
    FIELD(record, float *, 0x1C) = value1;
    FIELD(record, int *, 0x20) = arg3;
    FIELD(record, int *, 0x24) = arg4;
}
}
