typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK Chaser_SetState(s8 *, M2C_UNK);           /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s8 *); /* extern */
s32 func_0017F1D0(s8 *);                          /* extern */
extern M2C_UNK B_002DEB30;

s32 Chaser_FTakeHit(s8 *arg0) {
    s32 temp_v0;
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x1C0) != 4) {
        if (func_0017F1D0(arg0) != 0) {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0x184);
            if (temp_v0 >= 0) {
                if (temp_v0 <= 0) {
                    bevy_camera_follow_activity(&B_002DEB30, 0x18, arg0);
                }
                Chaser_SetState(arg0, 4);
            }
            var_v0 = 1;
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_v0;
        }
        return 0;
    }
    return var_v0;
}

}
