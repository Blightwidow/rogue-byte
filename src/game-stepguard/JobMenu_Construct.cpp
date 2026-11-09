#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
f32 JobMenu_InitPage(void *);
s32 Menu_Construct();
extern M2C_UNK D_002D8468;

void *JobMenu_Construct(void *arg0) {
    Menu_Construct();
    M2C_FIELD(arg0, s32 *, 0x20) = 0x4E0;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D8468;
    JobMenu_InitPage(arg0);
    return arg0;
}

}
