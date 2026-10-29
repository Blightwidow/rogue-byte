typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001796D0 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

void GoalHit_Activate(s8 *);
void bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s8 *);
void func_00154038(s32, s32, M2C_UNK);
s32 func_001F78A0(s32);
extern M2C_UNK B_002DEB30;

void func_001796D0(s8 *arg0) {
    s32 *temp_v1;

    temp_v1 = (s32 *)(M2C_FIELD(arg0, s8 **, 0x10) + ((func_001F78A0(M2C_FIELD(arg0, s32 *, 0x5C)) * 0x10) + 0xA70));
    M2C_FIELD(arg0, s32 **, 0x40) = temp_v1;
    if (*temp_v1 == -1) {
        M2C_FIELD(arg0, s32 **, 0x40) = NULL;
    }
    GoalHit_Activate(arg0);
    bevy_camera_follow_activity(&B_002DEB30, 0x15, M2C_FIELD(arg0, s8 **, 0x10));
    func_00154038(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xF64), M2C_FIELD(arg0, s32 *, 0x50), 2);
}

}
