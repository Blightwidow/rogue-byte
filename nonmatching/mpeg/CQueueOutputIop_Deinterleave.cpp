typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CQueueOutputIop_Deinterleave {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0xAC];
};                                                  /* size = 0xC0 */
s32 CStackFrame_Construct(s8 *);
void CStackFrame_Destructor(s8 *, M2C_UNK);
void CopyAb__FPvT0Ui(s32, s32, s32);
s32 PvAllocStackImpl__Fi(s32 *);
void CQueueOutputIop_Deinterleave(s8 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s6;
    s32 var_fp;
    s32 var_s0;
    s32 var_s1;
    s32 var_s3;
    s32 var_s5;
    temp_s1 = M2C_FIELD(arg0, s32 *, 4);
    if ((temp_s1 == 0x10) && (M2C_FIELD(arg0, s32 *, 0xC) != 1)) {
        var_s5 = arg2;
        CStackFrame_Construct(sp);
        temp_s2 = M2C_FIELD(arg0, s32 *, 0xC) << 0xA;
        sp10 = temp_s2;
        M2C_FIELD(&sp10, s32 *, 4) = temp_s1;
        temp_s6 = PvAllocStackImpl__Fi(&sp10);
        if (arg1 != 0) {
            var_fp = arg1 - temp_s2;
            do {
                var_s1 = 0;
                var_s3 = 0;
                var_s0 = 0;
                if (temp_s2 > 0) {
                    do {
                        temp_a2 = M2C_FIELD(arg0, s32 *, 0x10);
                        temp_a0 = var_s1 << 0xA;
                        var_s1 += 1;
                        CopyAb__FPvT0Ui(temp_s6 + (temp_a0 + (var_s3 * temp_a2)), var_s5 + var_s0, temp_a2);
                        if (var_s1 >= M2C_FIELD(arg0, s32 *, 0xC)) {
                            var_s3 += 1;
                            var_s1 = 0;
                        }
                        var_s0 += M2C_FIELD(arg0, s32 *, 0x10);
                    } while (var_s0 < temp_s2);
                }
                temp_a0_2 = var_s5;
                var_s5 += temp_s2;
                CopyAb__FPvT0Ui(temp_a0_2, temp_s6, temp_s2);
                var_fp -= temp_s2;
            } while (var_fp != 0);
        }
        CStackFrame_Destructor(sp, 2);
    }
}
}
