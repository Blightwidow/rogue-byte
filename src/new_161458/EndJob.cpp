typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EndJob {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
void LeaveTaskIfCurrent(s8 *);
void ResetJob();
void SetTaskState(s32, M2C_UNK);
void StopJobIfCurrent(s8 *);
void bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s8 *);
extern M2C_UNK B_002DEB30;
extern s8 *B_003E0FA0;
void EndJob(s8 *arg0) {
    ResetJob();
    SetTaskState(M2C_FIELD(arg0, s32 *, 0x64), 1);
    if (((s32)B_003E0FA0 != NULL) && (M2C_FIELD(B_003E0FA0, s32 *, 0x7C) == (s32)arg0)) {
        LeaveTaskIfCurrent(B_003E0FA0);
    }
    bevy_camera_follow_activity(&B_002DEB30, 0x1F, arg0);
    StopJobIfCurrent(arg0);
}
}
