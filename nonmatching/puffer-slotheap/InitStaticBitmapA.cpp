typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitStaticBitmapA {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK CopyBmpHeader(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK CopyPaletteHeader(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK CreateSlotheapSwAlign(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s32 B_002DD2E0;
extern s32 B_002DD2E4;
extern s32 B_002DD2E8;
extern s32 B_002DD2EC;
extern s32 B_002DD2F0;
extern s32 B_002DD2F4;
extern M2C_UNK B_002DD500;
extern M2C_UNK B_002DD520;
extern M2C_UNK B_004520A8;
extern M2C_UNK B_004520D0;
extern M2C_UNK B_004520F8;
extern M2C_UNK B_00452120;
extern M2C_UNK B_00452148;
extern M2C_UNK B_00452170;
extern M2C_UNK RO_0027A778;
extern M2C_UNK RO_0029A790;
extern M2C_UNK RO_0029A7C0;
void InitStaticBitmapA(s32 arg0, s32 arg1) {
    s32 temp_v0_16;
    s32 temp_v0_17;
    s32 temp_v0_18;
    s32 temp_v0_19;
    s32 temp_v0_20;
    s32 temp_v0_21;
    s8 *temp_v0;
    s8 *temp_v0_10;
    s8 *temp_v0_11;
    s8 *temp_v0_12;
    s8 *temp_v0_13;
    s8 *temp_v0_14;
    s8 *temp_v0_15;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    s8 *temp_v0_7;
    s8 *temp_v0_8;
    s8 *temp_v0_9;
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        M2C_FIELD(&RO_0029A7C0, s8 *, 0) = 0;
        M2C_FIELD(&RO_0029A7C0, s8 *, 3) = 0xF;
        M2C_FIELD(&RO_0029A7C0, s8 *, 1) = 0;
        M2C_FIELD(&RO_0029A7C0, s8 *, 2) = 0;
        temp_v0 = (s8 *)(&RO_0029A7C0 + 4);
        M2C_FIELD(&RO_0029A7C0, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0, s8 *, 3) = 0x7D;
        temp_v0_2 = temp_v0 + 4;
        M2C_FIELD(temp_v0, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_2, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_2, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_2, s8 *, 3) = 0x54;
        temp_v0_3 = temp_v0_2 + 4;
        M2C_FIELD(temp_v0_2, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_3, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_3, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_3, s8 *, 3) = 0x3F;
        temp_v0_4 = temp_v0_3 + 4;
        M2C_FIELD(temp_v0_3, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_4, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_4, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_4, s8 *, 3) = 0x2A;
        temp_v0_5 = temp_v0_4 + 4;
        M2C_FIELD(temp_v0_4, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_5, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_5, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_5, s8 *, 3) = 0x76;
        temp_v0_6 = temp_v0_5 + 4;
        M2C_FIELD(temp_v0_5, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_6, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_6, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_6, s8 *, 3) = 0x6E;
        temp_v0_7 = temp_v0_6 + 4;
        M2C_FIELD(temp_v0_6, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_7, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_7, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_7, s8 *, 3) = 0x1F;
        temp_v0_8 = temp_v0_7 + 4;
        M2C_FIELD(temp_v0_7, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_8, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_8, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_8, s8 *, 3) = 0x4D;
        temp_v0_9 = temp_v0_8 + 4;
        M2C_FIELD(temp_v0_8, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_9, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_9, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_9, s8 *, 3) = 0x80;
        temp_v0_10 = temp_v0_9 + 4;
        M2C_FIELD(temp_v0_9, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_10, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_10, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_10, s8 *, 3) = 0x47;
        temp_v0_11 = temp_v0_10 + 4;
        M2C_FIELD(temp_v0_10, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_11, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_11, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_11, s8 *, 3) = 0x12;
        temp_v0_12 = temp_v0_11 + 4;
        M2C_FIELD(temp_v0_11, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_12, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_12, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_12, s8 *, 3) = 0x60;
        temp_v0_13 = temp_v0_12 + 4;
        M2C_FIELD(temp_v0_12, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_13, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_13, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_13, s8 *, 3) = 0x36;
        temp_v0_14 = temp_v0_13 + 4;
        M2C_FIELD(temp_v0_14, s8 *, 3) = 0x80;
        M2C_FIELD(temp_v0_13, s8 *, 4) = 0;
        M2C_FIELD(temp_v0_14, s8 *, 1) = 0;
        M2C_FIELD(temp_v0_14, s8 *, 2) = 0;
        temp_v0_15 = temp_v0_14 + 4;
        M2C_FIELD(temp_v0_15, s8 *, 2) = 0x67;
        M2C_FIELD(temp_v0_14, s8 *, 4) = 0x67;
        M2C_FIELD(temp_v0_15, s8 *, 1) = 0x67;
        M2C_FIELD(temp_v0_15, s8 *, 3) = 0;
        CopyPaletteHeader(&B_002DD500, &RO_0027A778, 0x3F, 0x2A);
        CopyBmpHeader(&B_002DD520, &RO_0029A790);
        temp_v0_16 = B_002DD2E0 + 1;
        B_002DD2E0 = temp_v0_16;
        if (temp_v0_16 == 1) {
            CreateSlotheapSwAlign(&B_004520A8, 0x14, 0x2000, 0x10);
        }
        temp_v0_17 = B_002DD2E4 + 1;
        B_002DD2E4 = temp_v0_17;
        if (temp_v0_17 == 1) {
            CreateSlotheapSwAlign(&B_004520D0, 0x18, 0x800, 0x10);
        }
        temp_v0_18 = B_002DD2E8 + 1;
        B_002DD2E8 = temp_v0_18;
        if (temp_v0_18 == 1) {
            CreateSlotheapSwAlign(&B_004520F8, 0x28, 0x200, 0x10);
        }
        temp_v0_19 = B_002DD2EC + 1;
        B_002DD2EC = temp_v0_19;
        if (temp_v0_19 == 1) {
            CreateSlotheapSwAlign(&B_00452120, 0x1C, 0x800, 0x10);
        }
        temp_v0_20 = B_002DD2F0 + 1;
        B_002DD2F0 = temp_v0_20;
        if (temp_v0_20 == 1) {
            CreateSlotheapSwAlign(&B_00452148, 0xC, 0xC8, 0x10);
        }
        temp_v0_21 = B_002DD2F4 + 1;
        B_002DD2F4 = temp_v0_21;
        if (temp_v0_21 == 1) {
            CreateSlotheapSwAlign(&B_00452170, 0x14, 0x100, 0x10);
        }
    }
}
}
