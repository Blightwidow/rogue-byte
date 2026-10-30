typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefreshOptionItem {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x38];
};                                                  /* size = 0x40 */
#define sp4 (*(s32 *)(sp + 0x04))
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
M2C_UNK RefGetGameSaveValue(s8 *, s32, M2C_UNK *); /* extern */
extern M2C_UNK B_003D4A60;
extern s32 B_003DD050;
extern s32 B_003E0FC0;
extern s32 B_003E0FD8;
extern s32 B_003E0FDC;
extern s32 B_003E0FE0;
extern s32 g_2c2d8c;
void RefreshOptionItem(s32 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 temp_v0;
    s32 var_s0;
    s32 var_v0;
    temp_v0 = *arg0;
    switch (temp_v0) {
    case 0x4C:
    case 0x4D:
    case 0x4E:
        RefGetGameSaveValue(sp, B_003E0FC0, &B_003D4A60);
        CRef_Destruct(sp);
        if (sp4 != 1) {
            var_v0 = 0x4E;
            if (sp4 >= 2) {
                var_v0 = 0x4E;
                if (sp4 != 2) {
                } else {
                    var_v0 = 0x4D;
                }
            }
        } else {
            var_v0 = 0x4C;
        }
block_26:
        *arg0 = var_v0;
        break;
    case 0x4F:
    case 0x50:
        var_v0 = (B_003DD050 != 0) ? 0x4F : 0x50;
        goto block_26;
    case 0x48:
    case 0x49:
        if (g_2c2d8c != 2) {
            if (g_2c2d8c < 3) {
                var_s0 = 0;
                if (g_2c2d8c != 1) {
                } else {
                    RefGetGameSaveValue(sp, B_003E0FD8, &B_003D4A60);
                    var_s0 = sp4;
                    CRef_Destruct(sp);
                }
            } else {
                var_s0 = 0;
                if (g_2c2d8c != 3) {
                } else {
                    var_s0 = 1;
                }
            }
        } else {
            var_s0 = 0;
        }
        var_v0 = 0x49;
        if (var_s0 == 0) {
            var_v0 = 0x48;
        }
        goto block_26;
    case 0x51:
    case 0x52:
        RefGetGameSaveValue(sp, B_003E0FDC, &B_003D4A60);
        CRef_Destruct(sp);
        var_v0 = 0x52;
        if (sp4 == 0) {
            var_v0 = 0x51;
        }
        goto block_26;
    case 0x53:
    case 0x54:
        RefGetGameSaveValue(sp, B_003E0FE0, &B_003D4A60);
        CRef_Destruct(sp);
        var_v0 = 0x53;
        if (sp4 != 0) {
            var_v0 = 0x54;
        }
        goto block_26;
    }
}
}
