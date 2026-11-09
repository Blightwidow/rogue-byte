#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void PostScriptMessage();
void bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s32);
extern M2C_UNK B_002DEB30;

void HandleLoSpliceEvent(s32 arg0, s32 arg1) {
    PostScriptMessage();
    switch (arg1) {                                 /* irregular */
    case 5:
        bevy_camera_follow_activity(&B_002DEB30, 0x1A, arg0);
        return;
    case 6:
        bevy_camera_follow_activity(&B_002DEB30, 0x1B, arg0);
        break;
    }
}

}
