typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CGc_Collect {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0xAC];
};                                                  /* size = 0xC0 */
M2C_UNK CGc_MarkRef(s8 *, s8 *);                /* extern */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK);    /* extern */
s32 PvAllocStackImpl__Fi(s32 *);                    /* extern */
M2C_UNK SweepFrames();                              /* extern */
M2C_UNK SweepPairs();                               /* extern */
M2C_UNK SweepProcs();                               /* extern */
M2C_UNK SweepSidebags();                            /* extern */
M2C_UNK SweepVarbs();                               /* extern */
M2C_UNK bevy_splice_eval_reset(s8 *);             /* extern */
M2C_UNK func_002574E0();                            /* extern */
M2C_UNK func_002574E8();                            /* extern */
M2C_UNK func_002574F0();                            /* extern */
M2C_UNK func_002574F8();                            /* extern */
M2C_UNK func_00257500();                            /* extern */
M2C_UNK func_00257508();                            /* extern */
M2C_UNK func_00257C18();                            /* extern */
extern s8 *B_002DD2AC;
extern s8 *B_002DD2CC;
extern s8 *B_003E0E80;
extern s32 B_004520B8;
extern M2C_UNK B_004520E8;
extern s32 B_00452108;
extern s32 B_00452130;
extern M2C_UNK B_00452138;
extern s32 g_2dd598;
void CGc_Collect(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s32 sp10;
    s32 temp_a0_2;
    s32 temp_a0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_v0_2;
    u32 temp_a0;
    u32 temp_a0_3;
    u32 temp_a0_5;
    u32 temp_v0;
    u32 temp_v0_2;
    s8 *temp_a1;
    s8 *var_a1;
    s8 *var_a2;
    s8 *var_s0;
    s8 *var_s2;
    s8 *var_v0;
    s8 *var_v0_3;
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) == 0);
    func_002574E0();
    func_002574E8();
    func_002574F0();
    func_002574F8();
    func_00257500();
    func_00257508();
    CStackFrame_Construct(sp);
    sp10 = B_00452108 * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 8) = PvAllocStackImpl__Fi(&sp10);
    M2C_FIELD(arg0, s32 *, 4) = 0;
    sp10 = B_004520B8 * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x10) = PvAllocStackImpl__Fi(&sp10);
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    sp10 = B_00452130 * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    var_a1 = B_002DD2AC;
    M2C_FIELD(arg0, s32 *, 0x18) = PvAllocStackImpl__Fi(&sp10);
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    if (var_a1 != NULL) {
        do {
            temp_a0 = M2C_FIELD(var_a1, u32 *, 4);
            if ((temp_a0 >> 0x1F) != g_2dd598) {
                M2C_FIELD(var_a1, u32 *, 4) = (u32) ((temp_a0 & 0x7FFFFFFF) | (g_2dd598 << 0x1F));
                temp_v1 = M2C_FIELD(arg0, s32 *, 4);
                *(s32 *)((temp_v1 * 4) + M2C_FIELD(arg0, s32 *, 8)) = (int)(var_a1);
                M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_v1 + 1);
            }
            temp_v0 = M2C_FIELD(var_a1, u32 *, 4);
            temp_a0_2 = (temp_v0 >> 0x10) & 0x1FFF;
            temp_v1_2 = (temp_v0 >> 0x1D) & 3;
            if ((temp_a0_2 != 0) || (var_v0 = NULL, (temp_v1_2 != 0))) {
                var_v0 = (s8 *)(*((temp_v1_2 * 4) + &B_004520E8) + (temp_a0_2 * 0x28));
            }
            var_a1 = var_v0;
        } while (var_a1 != NULL);
    }
    var_s2 = B_002DD2CC;
    if (var_s2 != NULL) {
        do {
            temp_a0_3 = M2C_FIELD(var_s2, u32 *, 4);
            if ((temp_a0_3 >> 0x1F) != g_2dd598) {
                M2C_FIELD(var_s2, u32 *, 4) = (u32) ((temp_a0_3 & 0x7FFFFFFF) | (g_2dd598 << 0x1F));
            }
            var_s0 = M2C_FIELD(var_s2, s8 **, 8);
            if (var_s0 != NULL) {
                var_v0_2 = M2C_FIELD(var_s0, s32 *, 4);
loop_14:
                M2C_FIELD(var_s0, s32 *, 4) = (s32) ((var_v0_2 & 0x7FFFFFFF) | (g_2dd598 << 0x1F));
                CGc_MarkRef(arg0, var_s0 + 0xC);
                var_s0 = M2C_FIELD(var_s0, s8 **, 0x14);
                if (var_s0 != NULL) {
                    var_v0_2 = M2C_FIELD(var_s0, s32 *, 4);
                    goto loop_14;
                }
            }
            temp_v0_2 = M2C_FIELD(var_s2, u32 *, 4);
            temp_a0_4 = (temp_v0_2 >> 0x10) & 0x1FFF;
            temp_v1_3 = (temp_v0_2 >> 0x1D) & 3;
            if ((temp_a0_4 != 0) || (var_v0_3 = NULL, (temp_v1_3 != 0))) {
                var_v0_3 = (s8 *)(*((temp_v1_3 * 4) + &B_00452138) + (temp_a0_4 * 0xC));
            }
            var_s2 = var_v0_3;
        } while (var_s2 != NULL);
    }
    var_a2 = B_003E0E80;
    if (var_a2 != NULL) {
        do {
            temp_a1 = M2C_FIELD(var_a2, s8 **, 8);
            temp_a0_5 = M2C_FIELD(temp_a1, u32 *, 4);
            if ((temp_a0_5 >> 0x1F) != g_2dd598) {
                M2C_FIELD(temp_a1, u32 *, 4) = (u32) ((temp_a0_5 & 0x7FFFFFFF) | (g_2dd598 << 0x1F));
                temp_v1_4 = M2C_FIELD(arg0, s32 *, 0xC);
                *(s32 *)((temp_v1_4 * 4) + M2C_FIELD(arg0, s32 *, 0x10)) = (int)(temp_a1);
                M2C_FIELD(arg0, s32 *, 0xC) = (s32) (temp_v1_4 + 1);
            }
            var_a2 = M2C_FIELD(var_a2, s8 **, 0x10);
        } while (var_a2 != NULL);
    }
    bevy_splice_eval_reset(arg0);
    SweepFrames();
    SweepVarbs();
    SweepPairs();
    SweepProcs();
    SweepSidebags();
    func_00257C18();
    CStackFrame_Destructor(sp, 2);
}
}
