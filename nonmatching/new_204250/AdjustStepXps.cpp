typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AdjustStepXps {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK FreeSwMqList__FP2SWP2MQ(M2C_UNK *, s8 *, s8 **, s8 **); /* extern */
M2C_UNK func_001F4F10();                            /* extern */
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;
void AdjustStepXps(s8 *arg0) {
    f32 temp_f0;
    f32 var_f1;
    s32 var_v0;
    s32 var_v0_2;
    s8 **var_a2;
    s8 **var_a2_2;
    s8 **var_a3;
    s8 *var_a0;
    s8 *var_a1;
    s8 *var_t1;
    s8 *var_v1;
    func_001F4F10();
    var_f1 = 3.4028235e38f;
    var_t1 = NULL;
    var_a2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 ***, 0x64);
loop_1:
    if (var_a2 == NULL) {
        var_v1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 **, 0x68);
    } else {
        var_v1 = M2C_FIELD(var_a2, s8 **, 0);
    }
    if (var_v1 != NULL) {
        var_v0 = M2C_FIELD(var_v1, s32 *, 0x9C);
loop_8:
        if (var_v0 == 0xE) {
            temp_f0 = M2C_FIELD(var_v1, f32 *, 0x90);
            if (temp_f0 < var_f1) {
                var_f1 = temp_f0;
                var_t1 = var_v1;
            }
        }
        var_v1 = M2C_FIELD(var_v1, s8 **, 0xAC);
        if (var_v1 != NULL) {
            var_v0 = M2C_FIELD(var_v1, s32 *, 0x9C);
            goto loop_8;
        }
    }
    if (var_a2 != NULL) {
        var_a2 = M2C_FIELD(var_a2, s8 ***, 4);
        goto loop_1;
    }
    M2C_FIELD(arg0, s8 **, 0x208) = var_t1;
    if (var_t1 != NULL) {
        M2C_FIELD(arg0, f32 *, 0x20C) = (f32) g_2dded0;
        M2C_FIELD(arg0, s128 *, 0x230) = (s128) M2C_FIELD(var_t1, s128 *, 0x50);
    }
    var_a1 = NULL;
    var_a2_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 ***, 0x64);
loop_19:
    var_a3 = var_a2_2;
    if (var_a2_2 == NULL) {
        var_a3 = (s8 **)(M2C_FIELD(arg0, s8 **, 0xEC) + 0x68);
    }
    var_a0 = *var_a3;
    if (var_a0 != NULL) {
        var_v0_2 = M2C_FIELD(var_a0, s32 *, 8);
loop_23:
        if (M2C_FIELD((var_a0 + (((s32) (s32)arg0 != var_v0_2) << 6)), s32 *, 0xC) != (s32)arg0) {
            var_a3 = (s8 **)(var_a0 + 0xAC);
        } else if (M2C_FIELD(var_a0, s32 *, 0x9C) != 0xE) {
            var_a3 = (s8 **)(var_a0 + 0xAC);
        } else if (var_a0 == var_t1) {
            var_a3 = (s8 **)(var_a0 + 0xAC);
        } else {
            *var_a3 = M2C_FIELD(var_a0, s8 **, 0xAC);
            M2C_FIELD(var_a0, s8 **, 0xAC) = var_a1;
            var_a1 = var_a0;
        }
        var_a0 = *var_a3;
        if (var_a0 != NULL) {
            var_v0_2 = M2C_FIELD(var_a0, s32 *, 8);
            goto loop_23;
        }
    }
    if (var_a2_2 != NULL) {
        *M2C_FIELD(var_a2_2, s32 **, 8) = (int)(M2C_FIELD(var_a2_2, s8 **, 0));
        var_a2_2 = M2C_FIELD(var_a2_2, s8 ***, 4);
        goto loop_19;
    }
    FreeSwMqList__FP2SWP2MQ(&B_003DD490, var_a1, var_a2_2, var_a3);
}
}
