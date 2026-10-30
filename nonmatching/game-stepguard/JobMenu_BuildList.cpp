typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_JobMenu_BuildList {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ s8 **sp8;                          /* inferred */
    /* 0x0C */ char padC[0x84];
};                                                  /* size = 0x90 */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
M2C_UNK JobMenu_Select(s8 *, s32);                /* extern */
M2C_UNK OrderTasks(s32 *, s8 ***);                /* extern */
s32 func_00163430(s8 *);                          /* extern */
M2C_UNK func_00213928(s32, s32);                    /* extern */
M2C_UNK memmove(s8 *, s8 *, s32);               /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK qsort(s8 **, s32, M2C_UNK, M2C_UNK *);    /* extern */
extern M2C_UNK func_00165C28;
void JobMenu_BuildList(s8 *arg0) {
    s8 sp[0x90] __attribute__((aligned(16)));
    s32 sp4;
    s8 **sp8;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_a3;
    s32 var_s2;
    s32 var_s3;
    s32 var_t0;
    s8 *temp_a0;
    s8 *temp_s0;
    s8 *temp_v0_2;
    s8 *temp_v1_2;
    s8 *var_a2;
    s8 *var_s0;
    s8 *var_s4;
    /* Flowgraph is not reducible, falling back to gotos-only mode. */
    var_s3 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x48) <= 0) {
        goto block_7;
    }
    var_s0 = arg0 + 0x4C;
loop_2:
    temp_a1 = M2C_FIELD(var_s0, s32 *, 4);
    if (temp_a1 == -1) {
        goto block_4;
    }
    func_00213928(M2C_FIELD(arg0, s32 *, 0x24), temp_a1);
    M2C_FIELD(var_s0, s32 *, 4) = -1;
block_4:
    temp_a1_2 = M2C_FIELD(var_s0, s32 *, 8);
    if (temp_a1_2 == -1) {
        goto block_6;
    }
    func_00213928(M2C_FIELD(arg0, s32 *, 0x24), temp_a1_2);
    M2C_FIELD(var_s0, s32 *, 8) = -1;
block_6:
    var_s3 += 1;
    var_s0 += 0xC;
    if (var_s3 < M2C_FIELD(arg0, s32 *, 0x48)) {
        goto loop_2;
    }
block_7:
    temp_a0 = arg0 + 0x4C;
    M2C_FIELD(arg0, s32 *, 0x118) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    memset(temp_a0, 0, 0);
    CStackFrame_Construct(sp);
    OrderTasks(&sp4, &sp8);
    qsort(sp8, sp4, 4, &func_00165C28);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x40);
    if (temp_v1 == 0) {
        goto block_10;
    }
    if (temp_v1 == 1) {
        goto block_21;
    }
    goto block_31;
block_10:
    var_s4 = NULL;
    var_s2 = 0;
    if (sp4 <= 0) {
        goto block_31;
    }
loop_12:
    temp_s0 = M2C_FIELD(sp8[var_s2], s8 **, 0x7C);
    if (temp_s0 == NULL) {
        goto block_19;
    }
    if (var_s4 == temp_s0) {
        goto block_19;
    }
    var_s4 = temp_s0;
    if (func_00163430(temp_s0) <= 0) {
        goto block_18;
    }
    if (M2C_FIELD(temp_s0, s32 *, 0x6C) == -1) {
        goto block_19;
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x48);
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) (temp_v0 + 1);
    temp_v1_2 = arg0 + ((temp_v0 * 0xC) + 0x4C);
    M2C_FIELD(temp_v1_2, s32 *, 4) = -1;
    M2C_FIELD(temp_v1_2, s8 **, 0) = temp_s0;
    M2C_FIELD(temp_v1_2, s32 *, 8) = -1;
    if (M2C_FIELD(arg0, s32 *, 0x110) != (s32)temp_s0) {
        goto block_19;
    }
    M2C_FIELD(arg0, s32 *, 0x118) = (s32) ((s32) (((temp_v1_2 - 0x4C) - arg0) * 0xAAAAAAAB) >> 2);
block_18:
block_19:
    var_s2 += 1;
    if (var_s2 < sp4) {
        goto loop_12;
    }
    goto block_31;
block_21:
    var_t0 = 0;
    var_a3 = 0;
    if (sp4 <= 0) {
        goto block_31;
    }
    var_a2 = *sp8;
    if (M2C_FIELD(arg0, s32 *, 0x110) != M2C_FIELD(var_a2, s32 *, 0x7C)) {
        goto loop_26;
    }
    if (M2C_FIELD(var_a2, s32 *, 0x5C) == -1) {
        goto loop_26;
    }
block_24:
    temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x48);
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) (temp_v1_3 + 1);
    temp_v0_2 = arg0 + ((temp_v1_3 * 0xC) + 0x4C);
    M2C_FIELD(temp_v0_2, s32 *, 4) = -1;
    M2C_FIELD(temp_v0_2, s8 **, 0) = var_a2;
    M2C_FIELD(temp_v0_2, s32 *, 8) = -1;
    temp_v1_4 = M2C_FIELD(var_a2, s32 *, 0x54);
    var_a3 = ((temp_v1_4 ^ 1) == 0) ? 1 : var_a3;
    if (temp_v1_4 == 0) {
        goto block_31;
    }
loop_26:
    var_t0 += 1;
    if (var_t0 >= sp4) {
        goto block_31;
    }
    var_a2 = sp8[var_t0];
    if (M2C_FIELD(arg0, s32 *, 0x110) != M2C_FIELD(var_a2, s32 *, 0x7C)) {
        goto loop_26;
    }
    if (M2C_FIELD(var_a2, s32 *, 0x5C) == -1) {
        goto loop_26;
    }
    if (var_a3 == 0) {
        goto block_24;
    }
    if (M2C_FIELD(var_a2, s32 *, 0x54) != 0) {
        goto block_24;
    }
block_31:
    temp_a1_3 = M2C_FIELD(arg0, s32 *, 0x48);
    temp_v1_5 = M2C_FIELD(arg0, s32 *, 0x10C);
    if (temp_v1_5 >= temp_a1_3) {
        goto block_36;
    }
    memmove(temp_a0, arg0 + (((temp_a1_3 - temp_v1_5) * 0xC) + 0x4C), temp_v1_5 * 0xC);
    temp_a1_4 = M2C_FIELD(arg0, s32 *, 0x118);
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x48) - M2C_FIELD(arg0, s32 *, 0x10C);
    if (temp_v0_3 >= temp_a1_4) {
        goto block_34;
    }
    M2C_FIELD(arg0, s32 *, 0x118) = (s32) (temp_a1_4 - temp_v0_3);
    goto block_35;
block_34:
    M2C_FIELD(arg0, s32 *, 0x118) = 0;
block_35:
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(arg0, s32 *, 0x10C);
block_36:
    JobMenu_Select(arg0, M2C_FIELD(arg0, s32 *, 0x118));
    CStackFrame_Destructor(sp, 2);
    return;
}
}
