typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CedgeFindAtPos {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of sp10[4]? */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ s32 sp24;                            /* inferred */
    /* 0x28 */ char pad28[0x78];
};                                                  /* size = 0xA0 */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
s32 PruneBsp__FP3BSPP6VECTORfPP3BSP(s32, M2C_UNK, s128, s32 *, s32 *, M2C_UNK); /* extern */
s32 PvAllocStackImpl__Fi(s32 *, s32, s32 *, M2C_UNK); /* extern */
s32 CedgeFindAtPos(s8 *arg0, s8 *arg1, s32 arg2, s32 arg3, s32 *arg4) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp20;
    s32 sp24;
    s32 *var_v1;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a4;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s8 **var_a2;
    s8 *var_a1;
    CStackFrame_Construct(sp);
    temp_a0 = M2C_FIELD(arg1, s32 *, 4);
    temp_v1 = (temp_a0 <= 0x1554) ? temp_a0 : 0x1555;
    temp_a1 = temp_v1 * 0xC;
    sp20 = temp_v1;
    sp10 = temp_a1;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v0 = PvAllocStackImpl__Fi(&sp10, temp_a1, &sp10, 0x10);
    sp24 = temp_v0;
    if (PruneBsp__FP3BSPP6VECTORfPP3BSP(M2C_FIELD(arg1, s32 *, 0xC), 0x7FFFFFFF, *(s32 *)((arg2 * 0x10) + M2C_FIELD(arg0, s32 *, 4)), &sp20, &sp24, 0x3F800000) != 2) {
        CStackFrame_Destructor(sp, 2);
        return 0;
    }
    var_a0 = 0;
    temp_a4 = (s32) ((sp24 - temp_v0) * 0xAAAAAAAB) >> 2;
    var_s0 = 0;
    if (temp_a4 > 0) {
        var_v0 = 0 * 0xC;
        do {
            var_a1 = M2C_FIELD(M2C_FIELD((var_v0 + temp_v0), s8 **, 8), s8 **, 0x10);
            if (var_a1 != NULL) {
                var_a2 = (s8 **)((var_s0 * 4) + arg4);
                do {
                    if ((arg2 == M2C_FIELD(var_a1, u16 *, 0)) || (arg2 == M2C_FIELD(var_a1, u16 *, 2))) {
                        var_a0_2 = 0;
                        if (var_s0 > 0) {
                            var_v0_2 = var_s0 > 0;
                            if ((s32)var_a1 != *arg4) {
                                var_v1 = arg4;
loop_11:
                                var_a0_2 += 1;
                                var_v1 += 4;
                                if (var_a0_2 < var_s0) {
                                    if ((s32)var_a1 == *var_v1) {
                                        var_v0_2 = var_a0_2 < var_s0;
                                        goto block_14;
                                    }
                                    goto loop_11;
                                }
                                goto block_15;
                            }
block_14:
                            if (var_v0_2 == 0) {
                                goto block_15;
                            }
                        } else {
block_15:
                            if (var_s0 < arg3) {
                                *var_a2 = var_a1;
                                var_s0 += 1;
                                var_a2 += 4;
                            }
                        }
                    }
                    var_a1 = M2C_FIELD(var_a1, s8 **, 8);
                } while (var_a1 != NULL);
            }
            var_a0 += 1;
            var_v0 = var_a0 * 0xC;
        } while (var_a0 < temp_a4);
    }
    CStackFrame_Destructor(sp, 2);
    return var_s0;
}
}
