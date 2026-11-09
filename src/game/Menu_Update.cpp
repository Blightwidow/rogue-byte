#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void Menu_SetDialog(void *, M2C_UNK, M2C_UNK);
void func_001D9870();
extern f32 g_2ddf0c;

void Menu_Update(void *arg0) {
    func_001D9870();
    if (M2C_FIELD(arg0, f32 *, 0x34) <= g_2ddf0c) {
        Menu_SetDialog(arg0, -1, -1);
    }
}

}
