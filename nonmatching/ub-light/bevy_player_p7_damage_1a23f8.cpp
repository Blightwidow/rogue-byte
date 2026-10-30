typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_player_p7_damage_1a23f8 {};  /* size 0x0 */
extern M2C_UNK D_002BFB28;
s32 bevy_player_p7_damage_1a23f8(s8 *arg0, s32 *arg1) {
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a2;
    s32 var_v1;
    s8 *temp_a0;
    temp_a2 = M2C_FIELD(arg0, s32 *, 4);
    var_v1 = 0;
    if (temp_a2 != -1) {
        temp_v0 = temp_a2 * 4;
        temp_a0 = arg0 + 0xD4;
        var_v1 = *(temp_a0 + temp_v0);
        var_a2 = temp_v0;
        if (var_v1 == 0) {
loop_3:
            temp_v0_2 = temp_a2_2 * 4;
            temp_a2_2 = *(var_a2 + &D_002BFB28);
            if (temp_a2_2 != -1) {
                var_v1 = *(temp_a0 + temp_v0_2);
                var_a2 = temp_v0_2;
                if (var_v1 == 0) {
                    goto loop_3;
                }
            }
        }
    }
    *arg1 = 0;
    return var_v1;
}
}
