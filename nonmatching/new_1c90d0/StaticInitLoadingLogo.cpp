typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_StaticInitLoadingLogo {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
M2C_UNK CreateSlotheapSwAlign(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */
extern s32 B_002DD2E0;
extern s32 B_002DD2E4;
extern s32 B_002DD2E8;
extern s32 B_002DD2EC;
extern s32 B_002DD2F0;
extern s32 B_002DD2F4;
extern M2C_UNK B_003D3A00;
extern M2C_UNK B_004520A8;
extern M2C_UNK B_004520D0;
extern M2C_UNK B_004520F8;
extern M2C_UNK B_00452120;
extern M2C_UNK B_00452148;
extern M2C_UNK B_00452170;
extern M2C_UNK D_002C1740;
extern M2C_UNK D_002C1BD8;
extern M2C_UNK D_STR_002C19C0;
extern M2C_UNK D_STR_002C1AC8;
extern M2C_UNK D_STR_002C1B50;
void StaticInitLoadingLogo(s32 arg0, s32 arg1) {
    M2C_UNK *temp_s0;
    M2C_UNK *temp_s0_2;
    M2C_UNK *temp_s0_3;
    M2C_UNK *temp_s0_4;
    s32 temp_a0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s8 *temp_s0_5;
    s8 *temp_v0;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        memset(&B_003D3A00, 0, 0xC);
        M2C_FIELD(&B_003D3A00, s32 *, 0) = 0x35;
        temp_v1 = (s8 *)(&B_003D3A00 + 8);
        M2C_FIELD(&B_003D3A00, M2C_UNK **, 4) = &D_002C1740;
        M2C_FIELD(&B_003D3A00, s8 *, 8) = 0x2F;
        temp_s0 = &B_003D3A00 + 0xC;
        M2C_FIELD(temp_v1, s8 *, 1) = 0x3A;
        M2C_FIELD(temp_v1, s8 *, 3) = 0x7F;
        M2C_FIELD(temp_v1, s8 *, 2) = 0x7F;
        memset(temp_s0, 0, 0xC);
        M2C_FIELD(&B_003D3A00, s32 *, 0xC) = 0x16;
        temp_v1_2 = (s8 *)(temp_s0 + 8);
        M2C_FIELD(temp_s0, M2C_UNK **, 4) = &D_STR_002C19C0;
        M2C_FIELD(temp_s0, s8 *, 8) = 0x2F;
        temp_s0_2 = temp_s0 + 0xC;
        M2C_FIELD(temp_v1_2, s8 *, 1) = 0x3A;
        M2C_FIELD(temp_v1_2, s8 *, 3) = 0x7F;
        M2C_FIELD(temp_v1_2, s8 *, 2) = 0x7F;
        memset(temp_s0_2, 0, 0xC);
        temp_v1_3 = (s8 *)(temp_s0_2 + 8);
        M2C_FIELD(temp_s0, s32 *, 0xC) = 0xB;
        M2C_FIELD(temp_s0_2, s8 *, 8) = 0x5F;
        M2C_FIELD(temp_s0_2, M2C_UNK **, 4) = &D_STR_002C1AC8;
        temp_s0_3 = temp_s0_2 + 0xC;
        M2C_FIELD(temp_v1_3, s8 *, 3) = 0x7F;
        M2C_FIELD(temp_v1_3, s8 *, 1) = 0x5F;
        M2C_FIELD(temp_v1_3, s8 *, 2) = 0x5F;
        memset(temp_s0_3, 0, 0xC);
        M2C_FIELD(temp_s0_2, s32 *, 0xC) = 0xB;
        M2C_FIELD(temp_s0_3, s8 *, 8) = 0x5F;
        M2C_FIELD(temp_s0_3, M2C_UNK **, 4) = &D_STR_002C1B50;
        temp_v0 = (s8 *)(temp_s0_3 + 8);
        temp_s0_4 = temp_s0_3 + 0xC;
        M2C_FIELD(temp_v0, s8 *, 3) = 0x7F;
        M2C_FIELD(temp_v0, s8 *, 1) = 0x5F;
        M2C_FIELD(temp_v0, s8 *, 2) = 0x5F;
        memset(temp_s0_4, 0, 0xC);
        M2C_FIELD(temp_s0_4, M2C_UNK **, 4) = &D_002C1BD8;
        M2C_FIELD(temp_s0_3, s32 *, 0xC) = 0x3E;
        temp_a0 = B_002DD2E0 + 1;
        M2C_FIELD(temp_s0_4, s8 *, 8) = 0x5F;
        temp_s0_5 = (s8 *)(temp_s0_4 + 8);
        M2C_FIELD(temp_s0_5, s8 *, 3) = 0x7F;
        M2C_FIELD(temp_s0_5, s8 *, 2) = 0x5F;
        B_002DD2E0 = temp_a0;
        M2C_FIELD(temp_s0_5, s8 *, 1) = 0x5F;
        if (temp_a0 == 1) {
            CreateSlotheapSwAlign(&B_004520A8, 0x14, 0x2000, 0x10);
        }
        temp_v0_2 = B_002DD2E4 + 1;
        B_002DD2E4 = temp_v0_2;
        if (temp_v0_2 == 1) {
            CreateSlotheapSwAlign(&B_004520D0, 0x18, 0x800, 0x10);
        }
        temp_v0_3 = B_002DD2E8 + 1;
        B_002DD2E8 = temp_v0_3;
        if (temp_v0_3 == 1) {
            CreateSlotheapSwAlign(&B_004520F8, 0x28, 0x200, 0x10);
        }
        temp_v0_4 = B_002DD2EC + 1;
        B_002DD2EC = temp_v0_4;
        if (temp_v0_4 == 1) {
            CreateSlotheapSwAlign(&B_00452120, 0x1C, 0x800, 0x10);
        }
        temp_v0_5 = B_002DD2F0 + 1;
        B_002DD2F0 = temp_v0_5;
        if (temp_v0_5 == 1) {
            CreateSlotheapSwAlign(&B_00452148, 0xC, 0xC8, 0x10);
        }
        temp_v0_6 = B_002DD2F4 + 1;
        B_002DD2F4 = temp_v0_6;
        if (temp_v0_6 == 1) {
            CreateSlotheapSwAlign(&B_00452170, 0x14, 0x100, 0x10);
        }
    }
}
}
