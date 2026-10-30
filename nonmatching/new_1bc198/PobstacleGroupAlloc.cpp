typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PobstacleGroupAlloc {
    /* 0x00 */ char pad0[0xC0];
};                                                  /* size = 0xC0 */
s32 AppendDlEntry(s8 **, s8 *);
s32 *PloNew(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
s32 PvAllocSwImpl__Fi(s8 *, s32, s32);
void RemoveDlEntry(s8 **, s8 *);
s32 memset(s8 *, M2C_UNK, M2C_UNK);
extern s8 *B_003E1A40;
s8 *PobstacleGroupAlloc(void) {
    s8 sp[0x40] __attribute__((aligned(16)));
    f32 *temp_v0_2;
    f32 temp_f0;
    s32 var_a0;
    s32 var_s0;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v0_3;
    s8 *temp_v1;
    temp_s0 = B_003E1A40;
    if (temp_s0 == NULL) {
        var_s0 = 0;
        do {
            temp_v0 = (s8 *)(PloNew(0xE, 0, 0x2CD, -1));
            temp_s0_2 = temp_v0 + 0x60;
            M2C_FIELD(temp_v0, s32 *, 0xE0) = 0;
            M2C_FIELD(temp_v0, s32 *, 0xE4) = 1;
            M2C_FIELD(temp_v0, s32 *, 0x1C0) = 1;
            memset(temp_s0_2, 0, 0x40);
            M2C_FIELD(temp_s0_2, f32 *, 0x14) = 1.0f;
            M2C_FIELD(temp_s0_2, f32 *, 0x3C) = 1.0f;
            M2C_FIELD(temp_s0_2, f32 *, 0x28) = 1.0f;
            M2C_FIELD(temp_v0, f32 *, 0x60) = 1.0f;
            M2C_FIELD(temp_v0, s32 *, 0xEC) = PvAllocSwImpl__Fi(sp, 0x80, 0x10);
            var_a0 = 0;
loop_3:
            temp_f0 = (f32) var_a0;
            temp_v0_2 = (f32 *)((var_a0 * 4) + M2C_FIELD(temp_v0, s32 *, 0xEC));
            var_a0 += 1;
            *temp_v0_2 = temp_f0;
            if (var_a0 < 0x20) {
                goto loop_3;
            }
            var_s0 += 1;
            M2C_FIELD(temp_v0, s32 *, 0xF0) = PvAllocSwImpl__Fi(sp, 0x80, 0x10);
            M2C_FIELD(temp_v0, s32 *, 0xF4) = PvAllocSwImpl__Fi(sp, 0x200, 0x10);
            M2C_FIELD(temp_v0, s32 *, 0x1EC) = PvAllocSwImpl__Fi(sp, 0x1F0, 0x10);
            temp_v0_3 = M2C_FIELD(temp_v0, s8 **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *), 0x4C)(temp_v0 + M2C_FIELD(temp_v0_3, s16 *, 0x48));
            AppendDlEntry(&B_003E1A40, temp_v0);
        } while (var_s0 < 0x10);
    }
    RemoveDlEntry(&B_003E1A40, temp_s0);
    temp_v1 = M2C_FIELD(temp_s0, s8 **, 0xC);
    M2C_FIELD(temp_s0, s32 *, 0x1E8) = -1;
    M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *), 0x44)(temp_s0 + M2C_FIELD(temp_v1, s16 *, 0x40));
    M2C_FIELD(temp_s0, s32 *, 0x1D8) = 0;
    return temp_s0;
}
}
