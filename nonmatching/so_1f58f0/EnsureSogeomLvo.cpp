typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EnsureSogeomLvo {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ M2C_UNK sp30;                        /* inferred */
    /* 0x30 */ char pad30[0x10];
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ char pad44[0x6C];
};                                                  /* size = 0xB0 */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
s32 PvAllocStackClearImpl__Fi(s32 *);               /* extern */
s32 PvAllocSwClearImpl__Fi(s32 *);                  /* extern */
s8 *PvAllocSwImpl__Fi(s32 *);                     /* extern */
void EnsureSogeomLvo(s8 *arg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
    M2C_UNK sp30;
    s32 sp40;
    s32 *temp_a0;
    s32 *temp_t0;
    s32 *var_v1;
    s32 temp_a2;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_t7;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_t1;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a3;
    u16 temp_a3_2;
    s8 *temp_t0_2;
    if (M2C_FIELD(arg0, s8 **, 0x10) == NULL) {
        CStackFrame_Construct(&sp30);
        sp40 = 0xC;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        M2C_FIELD(arg0, s8 **, 0x10) = PvAllocSwImpl__Fi(&sp40);
        sp40 = M2C_FIELD(arg0, s32 *, 0x90) * 0x10;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0) = PvAllocSwClearImpl__Fi(&sp40);
        sp40 = M2C_FIELD(arg0, s32 *, 0x90) * 0x10;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 4) = PvAllocSwClearImpl__Fi(&sp40);
        sp40 = M2C_FIELD(arg0, s32 *, 0x98) * 0xC;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 8) = PvAllocSwClearImpl__Fi(&sp40);
        sp40 = M2C_FIELD(arg0, s32 *, 0x98) * 4;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        temp_t7 = PvAllocStackClearImpl__Fi(&sp40);
        var_a0 = 0;
        if (M2C_FIELD(arg0, s32 *, 0xA0) > 0) {
            do {
                var_a1 = 0;
                temp_t2 = M2C_FIELD(arg0, s32 *, 0xA4) + (var_a0 * 0x10);
                var_v0 = 0 * 2;
loop_4:
                temp_a3 = *(s32 *)(temp_t2 + 4 + var_v0);
                var_a2 = 0;
                temp_a0 = (s32 *)((temp_a3 * 4) + temp_t7);
                temp_t0 = (s32 *)(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 8) + (temp_a3 * 0xC));
                var_v0_2 = 0 * 2;
loop_5:
                temp_t1 = var_a2 + 1;
                temp_a3_2 = *(s32 *)(temp_t2 + var_v0_2);
                var_a1_2 = 0;
                if (*temp_a0 > 0) {
                    if (temp_a3_2 != *temp_t0) {
                        var_v1 = temp_t0;
loop_8:
                        var_a1_2 += 1;
                        var_v1 += 4;
                        if (var_a1_2 < *temp_a0) {
                            if (temp_a3_2 == *var_v1) {
                                goto block_10;
                            }
                            goto loop_8;
                        }
                        goto block_11;
                    }
block_10:
                    var_a2 = temp_t1;
                    if (var_a1_2 >= *temp_a0) {
                        goto block_11;
                    }
                } else {
block_11:
                    var_a2 = temp_t1;
                    if (var_a1_2 < 3) {
                        *(temp_t0 + (*temp_a0 * 4)) = (s32) temp_a3_2;
                        *temp_a0 += 1;
                    }
                }
                var_v0_2 = var_a2 * 2;
                if (var_a2 < 2) {
                    goto loop_5;
                }
                var_a1 += 1;
                var_v0 = var_a1 * 2;
                if (var_a1 < 2) {
                    goto loop_4;
                }
                var_a0 += 1;
            } while (var_a0 < M2C_FIELD(arg0, s32 *, 0xA0));
        }
        var_a3 = 0;
        temp_a2 = M2C_FIELD(arg0, s32 *, 0x7C);
        if (M2C_FIELD(arg0, s32 *, 0x98) > 0) {
            var_t1 = 0;
            do {
                temp_t0_2 = (s8 *)(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 8) + var_t1);
                asm volatile("lqc2 vf3, (%0)" : : "r"((M2C_FIELD(temp_t0_2, s32 *, 4) * 0x10) + temp_a2));
                asm volatile("lqc2 vf1, (%0)" : : "r"((M2C_FIELD(temp_t0_2, s32 *, 0) * 0x10) + temp_a2));
                asm volatile("vsub.xyzw vf3, vf3, vf1");
                asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, (%0)" : : "r"((M2C_FIELD(temp_t0_2, s32 *, 8) * 0x10) + temp_a2));
                asm volatile("lqc2 vf1, (%0)" : : "r"((M2C_FIELD(temp_t0_2, s32 *, 0) * 0x10) + temp_a2));
                asm volatile("vsub.xyzw vf2, vf2, vf1");
                asm volatile("vopmula.xyz ACC, vf3, vf2");
                asm volatile("vopmsub.xyz vf3, vf2, vf3");
                asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
                asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, (%0)" : : "r"(M2C_FIELD(arg0, s32 *, 0x84) + (var_a3 << 5)));
                asm volatile("vmul.xyz vf3, vf3, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf3, vf3y");
                asm volatile("vmaddz.x vf3, vf2, vf3z");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_1));
                if (vu_1 < 0.0f) {
                    temp_v1 = M2C_FIELD(temp_t0_2, s32 *, 8);
                    M2C_FIELD(temp_t0_2, s32 *, 8) = (s32) M2C_FIELD(temp_t0_2, s32 *, 4);
                    M2C_FIELD(temp_t0_2, s32 *, 4) = temp_v1;
                }
                var_a3 += 1;
                var_t1 += 0xC;
            } while (var_a3 < M2C_FIELD(arg0, s32 *, 0x98));
        }
        CStackFrame_Destructor(&sp30, 2, temp_a2, var_a3);
    }
}
}
