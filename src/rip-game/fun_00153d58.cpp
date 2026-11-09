#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00153D58 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK InitXfm();                                  /* extern */
M2C_UNK func_001A6CA8(s8 *, M2C_UNK);             /* extern */
void func_00153D58(s8 *arg0) {
    s32 temp_v1;
    InitXfm();
    func_001A6CA8(arg0, 1);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x40);
    if ((temp_v1 ^ 1) & 1) {
        *(s32 *)temp_v1 = (s32) (*(s32 *)temp_v1 | 2);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) (temp_v1 | 2);
}
}
