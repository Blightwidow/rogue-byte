#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void ResetSlotheap(char *);
extern s32 B_002DD2A0;
extern s32 B_002DD2A4;
extern s32 B_002DD2A8;
extern s32 B_002DD2AC;
extern char B_004520F8;

void ResetFrameHeap(void) {
    B_002DD2A0 = 0;
    B_002DD2A8 = 0;
    B_002DD2AC = 0;
    B_002DD2A4 = 0;
    ResetSlotheap(&B_004520F8);
}

}
