typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ClsgMergeAlsg {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of sp10[4]? */
    /* 0x20 */ u32 sp20;                            /* inferred */
    /* 0x24 */ u32 sp24;                            /* inferred */
    /* 0x28 */ char pad28[0xA8];
};                                                  /* size = 0xD0 */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
M2C_UNK CopyAb__FPvT0Ui(s32, s8 *, s32);          /* extern */
s8 *PvAllocStackImpl__Fi(s32 *, s32);             /* extern */
s32 ClsgMergeAlsg(s32 arg0, u32 arg1, s32 arg2, u32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 saved_reg_s7;
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 sp10;
    u32 sp20;
    u32 sp24;
    f32 var_f0;
    f32 var_f1;
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_s0;
    s32 var_a4;
    s32 var_a6;
    s32 var_a7;
    s32 var_s7;
    s32 var_t2;
    u32 *var_a5;
    u32 temp_a2;
    u32 temp_t0;
    u32 temp_t1;
    s8 *temp_a1_2;
    s8 *var_s0;
    /* Flowgraph is not reducible, falling back to gotos-only mode. */
    var_s7 = saved_reg_s7;
    CStackFrame_Construct(sp);
    temp_a1 = arg4 * 0x60;
    sp10 = temp_a1;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_a1_2 = PvAllocStackImpl__Fi(&sp10, temp_a1);
    var_a7 = 0;
    var_a6 = 0;
    sp20 = arg1;
    var_t2 = 0;
    sp24 = arg3;
    temp_t1 = (arg2 * 0x60) + arg3;
    var_s0 = temp_a1_2;
    temp_t0 = (arg0 * 0x60) + arg1;
    if (arg6 == 0) {
        goto block_3;
    }
    if (arg6 == 1) {
        goto block_4;
    }
    goto loop_25;
block_3:
    var_s7 = 1;
    goto block_24;
block_4:
    var_s7 = 2;
    goto block_24;
block_6:
    if (sp20 >= temp_t0) {
        goto block_8;
    }
block_7:
    var_f1 = M2C_FIELD((sp20 + (var_a7 * 4)), f32 *, 0x40);
    goto block_9;
block_8:
    var_f1 = 3.4028235e38f;
block_9:
    if (sp24 >= temp_t1) {
        goto block_11;
    }
    var_f0 = M2C_FIELD((sp24 + (var_a6 * 4)), f32 *, 0x40);
    goto block_12;
block_11:
    var_f0 = 3.4028235e38f;
block_12:
    var_a4 = var_a7;
    if (!(var_f1 <= var_f0)) {
        goto block_14;
    }
    var_a7 = 1 - var_a4;
    var_a5 = &sp20;
    goto block_15;
block_14:
    var_a4 = var_a6;
    var_a6 = 1 - var_a4;
    var_a5 = &sp24;
block_15:
    temp_a3 = (var_a7 + var_a6) >= var_s7;
    temp_a2 = *var_a5;
    if (temp_a3 == var_t2) {
        goto block_22;
    }
    if (temp_a3 == 0) {
        goto block_18;
    }
    goto block_21;
block_18:
    M2C_FIELD(var_s0, f32 *, 0x44) = (f32) M2C_FIELD(temp_a2, f32 *, 0x44);
    M2C_FIELD(var_s0, s128 *, 0x10) = (s128) M2C_FIELD(temp_a2, s128 *, 0x10);
    M2C_FIELD(var_s0, s128 *, 0x30) = (s128) M2C_FIELD(temp_a2, s128 *, 0x30);
    M2C_FIELD(var_s0, s32 *, 0x50) = (s32) M2C_FIELD(temp_a2, s32 *, 0x50);
    var_s0 += 0x60;
    var_t2 = temp_a3;
    if (arg4 >= ((s32) ((var_s0 - temp_a1_2) * 0xAAAAAAAB) >> 5)) {
        goto block_22;
    }
    var_s0 -= 0x60;
    goto block_27;
block_21:
    M2C_FIELD(var_s0, f32 *, 0x40) = (f32) M2C_FIELD(temp_a2, f32 *, 0x40);
    M2C_FIELD(var_s0, s128 *, 0) = (s128) M2C_FIELD(temp_a2, s128 *, 0);
    M2C_FIELD(var_s0, s128 *, 0x20) = (s128) M2C_FIELD(temp_a2, s128 *, 0x20);
    M2C_FIELD(var_s0, s32 *, 0x4C) = (s32) M2C_FIELD(temp_a2, s32 *, 0x4C);
    var_t2 = temp_a3;
block_22:
    if (var_a4 != 1) {
        goto loop_25;
    }
    *var_a5 = temp_a2 + 0x60;
block_24:
loop_25:
    if (sp20 < temp_t0) {
        goto block_7;
    }
    if (sp24 < temp_t1) {
        goto block_6;
    }
block_27:
    temp_s0 = (s32) ((var_s0 - temp_a1_2) * 0xAAAAAAAB) >> 5;
    CopyAb__FPvT0Ui(arg5, temp_a1_2, temp_s0 * 0x60);
    CStackFrame_Destructor(sp, 2);
    return temp_s0;
}
}
