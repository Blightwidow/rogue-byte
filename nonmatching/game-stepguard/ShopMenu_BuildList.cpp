typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ShopMenu_BuildList {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[8];                        /* maybe part of sp4[3]? */
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x20];
    /* 0x30 */ M2C_UNK sp30;                        /* inferred */
    /* 0x30 */ char pad30[0xB0];
};                                                  /* size = 0xE0 */
#define sp4 (*(s32 *)(sp + 0x04))
M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
s32 FGadgetAcquired(s32);                           /* extern */
s32 FGadgetOnSale(s32);                             /* extern */
M2C_UNK ShopMenu_Select(s8 *, s32);               /* extern */
M2C_UNK __as__4CRefRC4CRef(M2C_UNK *, M2C_UNK *);   /* extern */
M2C_UNK func_001D8A38(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK sprintf(M2C_UNK *, M2C_UNK *, s32, s32);    /* extern */
extern M2C_UNK RO_002A79A0;
extern M2C_UNK RO_002A79D0;
extern M2C_UNK RO_002A79D8;
void ShopMenu_BuildList(s8 *arg0) {
    s8 sp[0x80] __attribute__((aligned(16)));
    M2C_UNK sp10;
    M2C_UNK sp30;
    s32 *var_v1;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a0;
    s32 var_s0;
    s32 var_s0_2;
    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x48) > 0) {
        var_v1 = (s32 *)(arg0 + 0x4C);
        do {
            *var_v1 = -1;
            var_a0 += 1;
            var_v1 += 8;
        } while (var_a0 < M2C_FIELD(arg0, s32 *, 0x48));
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    if (temp_v1 != 0) {
        var_s0 = 0;
        if (temp_v1 != 1) {
        } else {
loop_17:
            sprintf(&sp10, &RO_002A79A0, var_s0, -1);
            func_001D8A38(&sp30, &RO_002A79D0, &RO_002A79D8, &sp10);
            __as__4CRefRC4CRef((M2C_UNK *)(sp), &sp30);
            CRef_Destruct(&sp30);
            if (sp4 != 0) {
                temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x48);
                if ((u32) temp_v1_2 < 0x41U) {
                    *(arg0 + 0x4C + (temp_v1_2 * 8)) = var_s0;
                    M2C_FIELD(arg0, s32 *, 0x48) = (s32) (temp_v1_2 + 1);
                    CRef_Destruct((M2C_UNK *)(sp));
                    goto block_23;
                }
                CRef_Destruct((M2C_UNK *)(sp));
            } else {
                CRef_Destruct((M2C_UNK *)(sp));
block_23:
                var_s0 += 1;
                if (var_s0 < 0x40) {
                    goto loop_17;
                }
            }
        }
    } else {
        var_s0_2 = 7;
loop_10:
        if (var_s0_2 < 0x2B) {
            if ((FGadgetOnSale(var_s0_2) != 0) && (FGadgetAcquired(var_s0_2) == 0)) {
                temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x48);
                if ((u32) temp_v1_3 >= 0x41U) {
                } else {
                    *(arg0 + 0x4C + (temp_v1_3 * 8)) = var_s0_2;
                    M2C_FIELD(arg0, s32 *, 0x48) = (s32) (temp_v1_3 + 1);
                    goto block_9;
                }
            } else {
block_9:
                var_s0_2 += 1;
                goto loop_10;
            }
        }
    }
    ShopMenu_Select(arg0, M2C_FIELD(arg0, s32 *, 0x24C));
}
}
