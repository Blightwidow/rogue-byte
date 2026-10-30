typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateJtGadgets {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
s32 FButtonPressedWithin(s8 *, s32, M2C_UNK);
s32 GetJtPower(s8 *);
s32 NewEmitter(...);
void SetEmitterUnpositioned(s32, M2C_UNK);
void SetJtGadgetSlotState(s8 *, s8 *, s32);
extern M2C_UNK D_002BCD00;
extern s32 D_002C3258;
extern f32 g_2dded0;
void UpdateJtGadgets(s8 *arg0) {
    s32 *var_s4;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_s1;
    s32 temp_v1;
    s32 var_s3;
    s8 *temp_s2;
    s8 *temp_v0;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    if (M2C_FIELD(arg0, s8 **, 0x150) != NULL) {
        var_s3 = 0;
        var_s4 = &D_002C3258;
        do {
            temp_a1 = *var_s4;
            temp_s2 = arg0 + ((var_s3 * 0xC) + 0x1180);
            temp_v1 = M2C_FIELD(temp_s2, s32 *, 4);
            temp_s1 = M2C_FIELD(temp_s2, s32 *, 0);
            switch (temp_v1) {                      /* irregular */
            case 1:
                if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), s32 *, 0x30) & temp_a1) {
                    temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                    if (M2C_FIELD(temp_v1_2, s32 (**)(s8 *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x318), temp_s1) != 0) {
                        temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
                        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *), 0x32C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x328), temp_s2);
                    } else {
                        goto block_17;
                    }
                } else {
block_17:
                    SetJtGadgetSlotState(arg0, temp_s2, 0);
                }
                break;
            case 0:
                if (FButtonPressedWithin(M2C_FIELD(arg0, s8 **, 0x150), temp_a1, 0x3E19999A) != 0) {
                    temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
                    if (M2C_FIELD(temp_v1_3, s32 (**)(s8 *, s32), 0x31C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x318), temp_s1) == 0) {
                        SetEmitterUnpositioned(NewEmitter(0x2E), 0);
                    } else {
                        temp_a1_2 = temp_s1 << 5;
                        if (GetJtPower(arg0) < M2C_FIELD((&D_002BCD00 + temp_a1_2), s32 *, 0xC)) {
                            SetEmitterUnpositioned(NewEmitter(0x2E, temp_a1_2, &D_002BCD00), 0);
                            M2C_FIELD(arg0, f32 *, 0x1304) = (f32) g_2dded0;
                        } else {
                            SetJtGadgetSlotState(arg0, temp_s2, *(temp_a1_2 + &D_002BCD00));
                        }
                    }
                }
                break;
            }
            var_s3 += 1;
            var_s4 += 4;
        } while (var_s3 < 3);
    }
}
}
