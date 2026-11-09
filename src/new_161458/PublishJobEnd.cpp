#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void SetTaskState(s32, M2C_UNK);
void StopJobIfCurrent(void *);
void TryAutosave(M2C_UNK *, M2C_UNK);
void bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *);
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_002E65E0;

void PublishJobEnd(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x78) == 0) {
        SetTaskState(M2C_FIELD(arg0, s32 *, 0x68), 3);
    }
    bevy_camera_follow_activity(&B_002DEB30, 0x20, arg0);
    StopJobIfCurrent(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x78) == 0) {
        TryAutosave(&B_002E65E0, 0);
    }
}

}
