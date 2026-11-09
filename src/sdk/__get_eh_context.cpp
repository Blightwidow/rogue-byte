#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack___get_eh_context {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
extern M2C_UNK (*D_002C60BC)();
void __get_eh_context(void) {
    D_002C60BC();
}
}
