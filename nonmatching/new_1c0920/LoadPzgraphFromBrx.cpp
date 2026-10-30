typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadPzgraphFromBrx {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
void CBinaryInputStream_ReadVector4(s32, s32);
s32 PvAllocSwClearImpl__Fi(s8 *, s32, s32);
s32 PvAllocSwImpl__Fi(s8 *, s32, s32);
s32 S32Read__18CBinaryInputStream(s8 *, s32);
s32 U16Read__18CBinaryInputStream(s32);
s32 U32Read__18CBinaryInputStream(s8 *, s32);
void LoadPzgraphFromBrx(s8 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s8 *temp_s0;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    var_s2 = 0;
    M2C_FIELD(arg0, s32 *, 8) = U32Read__18CBinaryInputStream(arg0, arg2);
    M2C_FIELD(arg0, s32 *, 0x10) = U32Read__18CBinaryInputStream(arg0, arg2);
    M2C_FIELD(arg0, s32 *, 4) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0) * 8, 0x10);
    M2C_FIELD(arg0, s32 *, 0xC) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 8) * 0x10, 0x10);
    M2C_FIELD(arg0, s32 *, 0x18) = PvAllocSwClearImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0x10) * 4, 0x10);
    M2C_FIELD(arg0, s32 *, 0x14) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0x10) * 4, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0) > 0) {
        do {
            temp_v0 = var_s2 * 8;
            var_s2 += 1;
            temp_s0 = (s8 *)(M2C_FIELD(arg0, s32 *, 4) + temp_v0);
            M2C_FIELD(temp_s0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + (U16Read__18CBinaryInputStream(arg2) * 0x10));
            M2C_FIELD(temp_s0, s16 *, 4) = U16Read__18CBinaryInputStream(arg2);
            M2C_FIELD(temp_s0, s16 *, 6) = U16Read__18CBinaryInputStream(arg2);
        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0));
    }
    var_s0 = 0;
    if (M2C_FIELD(arg0, s32 *, 8) > 0) {
loop_4:
        temp_a1 = var_s0 * 0x10;
        var_s0 += 1;
        CBinaryInputStream_ReadVector4(arg2, M2C_FIELD(arg0, s32 *, 0xC) + temp_a1);
        if (var_s0 < M2C_FIELD(arg0, s32 *, 8)) {
            goto loop_4;
        }
    }
    var_s0_2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x10) > 0) {
        do {
            temp_v1 = var_s0_2 * 4;
            var_s0_2 += 1;
            *(s32 *)(temp_v1 + M2C_FIELD(arg0, s32 *, 0x14)) = S32Read__18CBinaryInputStream(arg0, arg2);
        } while (var_s0_2 < M2C_FIELD(arg0, s32 *, 0x10));
    }
}
}
