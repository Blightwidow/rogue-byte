typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateSoRoot {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
M2C_UNK AddSoGeomsToOxa(s8 *);                    /* extern */
M2C_UNK RemoveSoGeomsFromOxa(s8 *);               /* extern */
M2C_UNK func_001A5B80();                            /* extern */
void UpdateSoRoot(s8 *arg0, s32 arg1, s8 *arg2) {
    s64 temp_v1;
    s64 temp_v1_2;
    s64 temp_v1_3;
    s8 *temp_v0;
    s8 *var_a0;
    s8 *var_a2;
    s8 *var_s0;
    s8 *var_s0_2;
    func_001A5B80();
    var_s0 = M2C_FIELD(arg0, s8 **, 0x64);
    if (var_s0 != NULL) {
        do {
            temp_v0 = M2C_FIELD(var_s0, s8 **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s32, s8 *), 0x6C)(var_s0 + M2C_FIELD(temp_v0, s16 *, 0x68), arg1, arg2);
            var_s0 = M2C_FIELD(var_s0, s8 **, 0x24);
        } while (var_s0 != NULL);
    }
    if (M2C_FIELD(arg0, s32 *, 0xE0) != 0) {
        temp_v1 = 0x8000 << 0x29;
        if (!(M2C_FIELD(arg0, s64 *, 0x28) & temp_v1)) {
            var_a2 = arg2;
            if ((s32)arg0 != arg1) {
                var_s0_2 = M2C_FIELD(arg0, s8 **, 0x10);
loop_6:
                if (!(M2C_FIELD(var_s0_2, s64 *, 0x28) & temp_v1)) {
                    if ((s32)var_s0_2 != arg1) {
                        var_s0_2 = M2C_FIELD(var_s0_2, s8 **, 0x10);
                        goto loop_6;
                    }
                    var_a2 = arg2;
                    goto block_11;
                }
            } else {
block_11:
                var_a0 = M2C_FIELD(arg0, s8 **, 0x10);
                if (var_a2 != NULL) {
                    temp_v1_2 = 0x8000 << 0x29;
                    if (!(M2C_FIELD(var_a2, s64 *, 0x28) & temp_v1_2)) {
loop_13:
                        var_a2 = M2C_FIELD(var_a2, s8 **, 0x10);
                        if (var_a2 != NULL) {
                            if (!(M2C_FIELD(var_a2, s64 *, 0x28) & temp_v1_2)) {
                                goto loop_13;
                            }
                        }
                    }
                }
                if (var_a0 != NULL) {
                    temp_v1_3 = 0x8000 << 0x29;
                    if (!(M2C_FIELD(var_a0, s64 *, 0x28) & temp_v1_3)) {
                        var_a0 = M2C_FIELD(var_a0, s8 **, 0x10);
loop_18:
                        if (var_a0 != NULL) {
                            if (!(M2C_FIELD(var_a0, s64 *, 0x28) & temp_v1_3)) {
                                var_a0 = M2C_FIELD(var_a0, s8 **, 0x10);
                                goto loop_18;
                            }
                        }
                    }
                }
                if ((var_a2 == NULL) && (var_a0 == NULL)) {
                    RemoveSoGeomsFromOxa(arg0);
                    AddSoGeomsToOxa(arg0);
                }
            }
        }
    }
}
}
