typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ApplySpriteKeySounds {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
s8 *NewEmitter(s32);                              /* extern */
M2C_UNK SetEmitterUnpositioned(s8 *, M2C_UNK);    /* extern */
M2C_UNK StartStream(M2C_UNK *, s32, M2C_UNK);       /* extern */
M2C_UNK StopAmb(s32, s32, M2C_UNK);                 /* extern */
M2C_UNK StopStream(M2C_UNK *);                      /* extern */
M2C_UNK VirtualRefPtr_Assign(s8 *, s8 *);       /* extern */
extern M2C_UNK B_003DD040;
void ApplySpriteKeySounds(s8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_v1;
    s32 var_s1;
    s8 *temp_a0;
    s8 *temp_s0;
    s8 *temp_s2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1_2;
    var_s1 = 0;
    temp_s2 = (s8 *)(M2C_FIELD(arg0, s32 *, 4) + (arg1 << 5));
    if (M2C_FIELD(temp_s2, u8 *, 0x18) != 0) {
        do {
            temp_a0 = (s8 *)((var_s1 * 8) + M2C_FIELD(temp_s2, s32 *, 0x1C));
            temp_v1 = M2C_FIELD(temp_a0, s32 *, 0);
            switch (temp_v1) {                      /* irregular */
            case 0:
                temp_v0 = NewEmitter(M2C_FIELD(temp_a0, s32 *, 4));
                SetEmitterUnpositioned(temp_v0, 0);
                temp_v1_2 = M2C_FIELD(temp_v0, s8 **, 0xC);
                if (M2C_FIELD(temp_v1_2, s32 (**)(s8 *), 0x44)(temp_v0 + M2C_FIELD(temp_v1_2, s16 *, 0x40)) == 2) {
                    VirtualRefPtr_Assign((s8 *)((arg2 * 0x18) + M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 8) + 0x14), temp_v0);
                }
                break;
            case 1:
                temp_a1 = arg2 * 0x18;
                temp_v0_2 = (s8 *)(temp_a1 + M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 8));
                if (M2C_FIELD(temp_v0_2, s32 *, 0x14) != 0) {
                    temp_s0 = temp_v0_2 + 0x14;
                    if (temp_s0 != NULL) {
                        temp_a0_2 = M2C_FIELD(temp_v0_2, s32 *, 0x14);
                        if (temp_a0_2 != 0) {
                            StopAmb(temp_a0_2, temp_a1, 0);
                            VirtualRefPtr_Assign(temp_s0, NULL);
                        }
                    }
                }
                break;
            case 2:
                StartStream(&B_003DD040, M2C_FIELD(temp_a0, s32 *, 4), 0);
                break;
            case 3:
                StopStream(&B_003DD040);
                break;
            }
            var_s1 += 1;
        } while (var_s1 < (s32) M2C_FIELD(temp_s2, u8 *, 0x18));
    }
}
}
