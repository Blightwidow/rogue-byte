#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void JobMenu_SetPage(M2C_UNK *, s32);
void bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, M2C_UNK);
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DA3C0;
extern s32 B_003E0F9C;

void func_001B0808(void) {
    bevy_camera_follow_activity(&B_002DEB30, 0x2B, 0);
    JobMenu_SetPage(&B_003DA3C0, B_003E0F9C != 0);
}

}
