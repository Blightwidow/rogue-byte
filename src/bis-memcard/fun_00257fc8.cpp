#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void ResetSlotheap(char *);
extern s32 B_002DD2D0;
extern s32 B_002DD2D8;
extern s32 B_002DD2DC;
extern char B_00452170;
extern s32 g_2dd2d4;

void func_00257FC8(void) {
    B_002DD2D0 = 0;
    B_002DD2D8 = 0;
    B_002DD2DC = 0;
    g_2dd2d4 = 0;
    ResetSlotheap(&B_00452170);
}

}
