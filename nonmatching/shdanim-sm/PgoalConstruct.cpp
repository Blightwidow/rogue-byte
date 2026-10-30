typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PgoalConstruct {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK func_002562A8(s8 *);                      /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK D_002CC1C0;
extern M2C_UNK D_002CC240;
extern M2C_UNK D_002CC2C0;
extern M2C_UNK D_002CC340;
extern M2C_UNK D_002CC3C0;
extern M2C_UNK D_002CC440;
extern M2C_UNK D_002CC4C0;
extern M2C_UNK D_002CCE90;
extern M2C_UNK D_002CDD40;
extern M2C_UNK D_002CDDC0;
extern M2C_UNK D_002CF7F8;
extern M2C_UNK D_002CFA10;
extern M2C_UNK D_002CFC20;
extern M2C_UNK D_002CFCA0;
extern M2C_UNK D_002CFD20;
extern M2C_UNK D_002CFDA0;
extern M2C_UNK D_002CFE20;
extern M2C_UNK D_002CFF20;
extern M2C_UNK D_002CFFA0;
extern M2C_UNK D_002D0020;
extern M2C_UNK D_002D00A0;
extern M2C_UNK D_002D0120;
extern M2C_UNK D_002D01A0;
extern M2C_UNK D_002D0220;
extern M2C_UNK D_002D02A0;
extern M2C_UNK D_002D0320;
extern M2C_UNK D_002D03A0;
extern M2C_UNK D_002D0420;
extern M2C_UNK D_002D04A0;
extern M2C_UNK D_002D0520;
extern M2C_UNK D_002D05A0;
extern M2C_UNK D_002D0620;
extern M2C_UNK D_002D06A0;
extern M2C_UNK D_002D07B0;
extern M2C_UNK D_002D0830;
extern M2C_UNK D_002D08B0;
extern M2C_UNK D_002D0930;
extern M2C_UNK D_002D0A30;
extern M2C_UNK D_002D0AB0;
extern M2C_UNK D_002D4AF8;
s8 *PgoalConstruct(s32 arg0, s8 *arg1, s8 *arg2) {
    M2C_UNK *var_v1;
    s8 *var_a2;
    var_a2 = arg2;
    switch (arg0) {
    case 0x9C:
        memset(arg1, 0, 0xB0);
        M2C_FIELD(arg1, s32 *, 0) = 0;
        M2C_FIELD(arg1, s32 *, 4) = 0;
        M2C_FIELD(arg1, M2C_UNK **, 0xC) = &D_002D04A0;
        memset(arg1 + 0x30, 0, 0x70);
block_43:
        var_a2 = arg1;
        break;
    case 0x9D:
        memset(arg1, 0, 0x50);
        var_a2 = arg1;
        var_v1 = &D_002D0AB0;
block_40:
        M2C_FIELD(arg1, s32 *, 0) = 0;
        M2C_FIELD(arg1, M2C_UNK **, 0xC) = var_v1;
        M2C_FIELD(arg1, s32 *, 4) = 0;
        break;
    case 0x9E:
        memset(arg1, 0, 0x50);
        var_a2 = arg1;
        var_v1 = &D_002D0A30;
        goto block_40;
    case 0x9F:
        memset(arg1, 0, 0x60);
        var_a2 = arg1;
        var_v1 = &D_002D07B0;
        goto block_40;
    case 0xA1:
        memset(arg1, 0, 0xC0);
        var_a2 = arg1;
        var_v1 = &D_002D0930;
        goto block_40;
    case 0xA2:
        memset(arg1, 0, 0xC0);
        var_a2 = arg1;
        var_v1 = &D_002D0830;
        goto block_40;
    case 0xA3:
        memset(arg1, 0, 0xC0);
        var_a2 = arg1;
        var_v1 = &D_002D08B0;
        goto block_40;
    case 0xA4:
        memset(arg1, 0, 0x50);
        var_a2 = arg1;
        var_v1 = &D_002D0620;
        goto block_40;
    case 0xA5:
        memset(arg1, 0, 0x60);
        var_a2 = arg1;
        var_v1 = &D_002D05A0;
        goto block_40;
    case 0xA7:
        memset(arg1, 0, 0xF0);
        var_a2 = arg1;
        var_v1 = &D_002D06A0;
        goto block_40;
    case 0xA9:
        memset(arg1, 0, 0x60);
        var_a2 = arg1;
        var_v1 = &D_002CF7F8;
        goto block_40;
    case 0xAA:
        memset(arg1, 0, 0x50);
        var_a2 = arg1;
        var_v1 = &D_002D0520;
        goto block_40;
    case 0xAB:
        memset(arg1, 0, 0xE0);
        var_a2 = arg1;
        var_v1 = &D_002CFA10;
        goto block_40;
    case 0xAE:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002D4AF8;
        goto block_40;
    case 0xAC:
        memset(arg1, 0, 0xA0);
        var_a2 = arg1;
        var_v1 = &D_002D0320;
        goto block_40;
    case 0xAF:
        memset(arg1, 0, 0x60);
        var_a2 = arg1;
        var_v1 = &D_002D02A0;
        goto block_40;
    case 0xB0:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002D0420;
        goto block_40;
    case 0xB1:
        memset(arg1, 0, 0x70);
        var_a2 = arg1;
        var_v1 = &D_002D03A0;
        goto block_40;
    case 0xAD:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002D0220;
        goto block_40;
    case 0xB2:
        memset(arg1, 0, 0x50);
        var_a2 = arg1;
        var_v1 = &D_002D01A0;
        goto block_40;
    case 0xB3:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002D0120;
        goto block_40;
    case 0xB4:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002CDDC0;
        goto block_40;
    case 0xB5:
        memset(arg1, 0, 0x60);
        var_a2 = arg1;
        var_v1 = &D_002CDD40;
        goto block_40;
    case 0xA8:
        memset(arg1, 0, 0xE0);
        var_a2 = arg1;
        var_v1 = &D_002CC4C0;
        goto block_40;
    case 0xC1:
        memset(arg1, 0, 0x50);
        var_a2 = arg1;
        var_v1 = &D_002CC440;
        goto block_40;
    case 0xC2:
        memset(arg1, 0, 0xA0);
        var_a2 = arg1;
        var_v1 = &D_002CC3C0;
        goto block_40;
    case 0xC3:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002CC340;
        goto block_40;
    case 0xC4:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002CC2C0;
        goto block_40;
    case 0xC5:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002CC240;
        goto block_40;
    case 0xB6:
        memset(arg1, 0, 0x50);
        var_a2 = arg1;
        var_v1 = &D_002CCE90;
        goto block_40;
    case 0xC6:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002CC1C0;
        goto block_40;
    case 0xB7:
        memset(arg1, 0, 0x70);
        var_a2 = arg1;
        var_v1 = &D_002D00A0;
        goto block_40;
    case 0xB8:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002D0020;
        goto block_40;
    case 0xB9:
        memset(arg1, 0, 0x40);
        var_a2 = arg1;
        var_v1 = &D_002CFFA0;
        goto block_40;
    case 0xBB:
        memset(arg1, 0, 0x30);
        var_a2 = arg1;
        var_v1 = &D_002CFF20;
        goto block_40;
    case 0xBA:
        memset(arg1, 0, 0xD0);
        M2C_FIELD(arg1, s32 *, 0) = 0;
        M2C_FIELD(arg1, s32 *, 4) = 0;
        M2C_FIELD(arg1, M2C_UNK **, 0xC) = &D_002CFE20;
        func_002562A8(arg1 + 0x40);
        func_002562A8(arg1 + 0x60);
        func_002562A8(arg1 + 0x80);
        goto block_43;
    case 0xBD:
        memset(arg1, 0, 0x50);
        var_a2 = arg1;
        var_v1 = &D_002CFD20;
        goto block_40;
    case 0xBE:
        memset(arg1, 0, 0x50);
        var_a2 = arg1;
        var_v1 = &D_002CFCA0;
        goto block_40;
    case 0xBF:
        memset(arg1, 0, 0x50);
        M2C_FIELD(arg1, s32 *, 0) = 0;
        M2C_FIELD(arg1, s32 *, 4) = 0;
        M2C_FIELD(arg1, M2C_UNK **, 0xC) = &D_002CFC20;
        func_002562A8(arg1 + 0x30);
        goto block_43;
    case 0xC0:
        memset(arg1, 0, 0x60);
        M2C_FIELD(arg1, s32 *, 0) = 0;
        M2C_FIELD(arg1, s32 *, 4) = 0;
        M2C_FIELD(arg1, M2C_UNK **, 0xC) = &D_002CFDA0;
        goto block_43;
    }
    return var_a2;
}
}
