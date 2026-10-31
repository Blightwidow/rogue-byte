typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateRunBlendFootsteps {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
f32 GModPositive__Fff(f32, f32);                    /* extern */
s32 NewEmitter(s32);                                /* extern */
s32 PosLoWorld(s32);                                /* extern */
M2C_UNK SetAmbPos(s32);                    /* extern */
M2C_UNK SetAmbRange(s32);         /* extern */
M2C_UNK SetAmbVolume(s32, f32);                     /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
void UpdateRunBlendFootsteps(s8 *arg0) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    s32 *var_s2;
    s32 temp_v0;
    s32 var_s3;
    s32 var_s5;
    s32 var_s6;
    s8 *temp_s0;
    s8 *temp_s4;
    s8 *temp_v1;
    var_s2 = (s32 *)(arg0 + 0x9C);
    var_s5 = 0;
    var_s6 = 0;
    temp_s4 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 4), s8 **, 0x50);
    temp_f21 = M2C_FIELD(temp_s4, f32 *, 0x1C);
    do {
        temp_v1 = M2C_FIELD(arg0, s8 **, 4);
        var_s3 = 1;
        temp_s0 = M2C_FIELD((var_s5 + M2C_FIELD(temp_v1, s32 *, 0xD0)), s8 **, 8);
        if (!(M2C_FIELD(temp_s0, f32 *, 4) <= GModPositive__Fff(temp_f21 - M2C_FIELD(temp_s0, f32 *, 0), M2C_FIELD(temp_v1, f32 *, 0x74)))) {
            var_s3 = 0;
        }
        if (var_s3 != *var_s2) {
            if (var_s3 == 0) {
                temp_f20 = M2C_FIELD(arg0, f32 *, 0x50);
                temp_f20_2 = (temp_f20 * M2C_FIELD(arg0, f32 *, 0x98)) + ((1.0f - temp_f20) * M2C_FIELD(arg0, f32 *, 0x94));
                temp_v0 = NewEmitter(M2C_FIELD(arg0, s32 *, 0x90));
                SetEmitterUnpositioned(temp_v0, 0);
                s64 vu_1;
                asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(M2C_FIELD(temp_s4, s32 *, 0x18))));
                SetAmbPos(temp_v0);
                SetAmbRange(temp_v0);
                SetAmbVolume(temp_v0, temp_f20_2);
            }
            *var_s2 = var_s3;
        }
        var_s6 += 1;
        var_s2 += 1;
        var_s5 += 0xC;
    } while (var_s6 < 2);
}
}
