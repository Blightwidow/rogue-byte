typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_BuildPzgraphAdjacency {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0x7C];
};                                                  /* size = 0x90 */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK, s32); /* extern */
s32 *PvAllocStackClearImpl__Fi(s32 *, M2C_UNK);     /* extern */
s32 PvAllocSwImpl__Fi(s32 *);                       /* extern */
void BuildPzgraphAdjacency(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s32 *temp_s0;
    s32 *temp_v1_2;
    s32 *var_s3;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1_4;
    s32 var_a0;
    s32 var_a2;
    s32 var_s1;
    s8 *temp_a0;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v0_4;
    s8 *temp_v1;
    s8 *temp_v1_3;
    CStackFrame_Construct(sp);
    sp10 = M2C_FIELD(arg0, s32 *, 0x10) * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_s0 = PvAllocStackClearImpl__Fi(&sp10, 0x10);
    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x20) > 0) {
loop_2:
        temp_v0 = (s8 *)(*(s32 *)((var_a0 * 4) + M2C_FIELD(arg0, s32 *, 0x24)));
        temp_v1 = M2C_FIELD(temp_v0, s8 **, 0x124);
        if ((temp_v1 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x128) != 0)) {
            temp_v1_2 = &temp_s0[M2C_FIELD(temp_v1, s32 *, 0x124)];
            *temp_v1_2 += 1;
        }
        var_a0 += 1;
        if (var_a0 < M2C_FIELD(arg0, s32 *, 0x20)) {
            goto loop_2;
        }
    }
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    var_s1 = 0;
    sp10 = M2C_FIELD(arg0, s32 *, 0x10) * 8;
    M2C_FIELD(arg0, s32 *, 0x1C) = PvAllocSwImpl__Fi(&sp10);
    if (M2C_FIELD(arg0, s32 *, 0x10) > 0) {
        var_s3 = temp_s0;
loop_10:
        temp_v0_2 = var_s1 * 8;
        var_s1 += 1;
        temp_s0_2 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x1C) + temp_v0_2);
        M2C_FIELD(temp_s0_2, s32 *, 0) = 0;
        temp_v0_3 = *var_s3;
        M2C_FIELD(&sp10, s32 *, 4) = 0x10;
        var_s3 += 4;
        M2C_FIELD(temp_s0_2, s32 *, 4) = PvAllocSwImpl__Fi(&sp10);
        sp10 = temp_v0_3 * 4;
        if (var_s1 < M2C_FIELD(arg0, s32 *, 0x10)) {
            goto loop_10;
        }
    }
    var_a2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x20) > 0) {
        do {
            temp_v0_4 = (s8 *)(*(s32 *)((var_a2 * 4) + M2C_FIELD(arg0, s32 *, 0x24)));
            temp_v1_3 = M2C_FIELD(temp_v0_4, s8 **, 0x124);
            if ((temp_v1_3 != NULL) && (M2C_FIELD(temp_v0_4, s32 *, 0x128) != 0)) {
                temp_a0 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x1C) + (M2C_FIELD(temp_v1_3, s32 *, 0x124) * 8));
                temp_v1_4 = M2C_FIELD(temp_a0, s32 *, 0);
                *(s32 *)((temp_v1_4 * 4) + M2C_FIELD(temp_a0, s32 *, 4)) = var_a2;
                M2C_FIELD(temp_a0, s32 *, 0) = (s32) (temp_v1_4 + 1);
            }
            var_a2 += 1;
        } while (var_a2 < M2C_FIELD(arg0, s32 *, 0x20));
    }
    CStackFrame_Destructor(sp, 2, var_a2);
}
}
