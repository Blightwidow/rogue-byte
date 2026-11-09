#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK Menu_Construct();                           /* extern */
void ShopMenu_InitPage(s8 *);                  /* extern */
extern M2C_UNK D_002D84E8;

s8 *ShopMenu_Construct(s8 *arg0) {
    Menu_Construct();
    M2C_FIELD(arg0, s32 *, 0x20) = 0x378;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D84E8;
    ShopMenu_InitPage(arg0);
    return arg0;
}

}
