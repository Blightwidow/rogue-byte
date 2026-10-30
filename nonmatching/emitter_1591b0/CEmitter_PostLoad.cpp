typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CEmitter_PostLoad {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
s32 AppendDlEntry(s8 *, s8 *);
void BindEmitter();
f32 GRandInRange(f32, f32);
s32 PauseEmitterIndefinite__FP7EMITTER(s8 *);
s32 PauseEmitter__FP7EMITTERf(s8 *, f32);
s32 *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, M2C_UNK);
s32 *PloNew(M2C_UNK, M2C_UNK, s32, M2C_UNK);
s32 PmatLoWorld(s8 *);
s32 *PvAllocSwCopyImpl__FiPv(s8 *, s32 *, s32, s32);
void QueueSwCallback(M2C_UNK *, s8 *, M2C_UNK, M2C_UNK);
void func_001A6CA8(s8 *, M2C_UNK);
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A5147;
void CEmitter_PostLoad(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    M2C_UNK temp_v0_2;
    M2C_UNK temp_v0_3;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f3;
    s32 *temp_a0;
    s32 *temp_a1;
    s32 *temp_v0;
    s32 temp_a0_3;
    s32 temp_a2;
    s32 var_v0;
    s8 *temp_a0_2;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s1;
    s8 *var_s2;
    BindEmitter();
    if (*M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xE4), s32 **, 8) != 0) {
        s32 vu_1;
        asm volatile("ldl %0, %%lo(RO_002A5147)(%1)" : "=r"(vu_1) : "r"(&RO_002A5147));
        s32 vu_2;
        asm volatile("ldr %0, %%lo(RO_002A5140)(%1)" : "=r"(vu_2) : "r"(&RO_002A5147), "0"(vu_1));
        QueueSwCallback(&B_003DD490, arg0, vu_2, 0);
    }
    if (M2C_FIELD(arg0, s32 *, 0xF0) == -1) {
        var_v0 = 3;
        if ((M2C_FIELD(arg0, f32 *, 0x104) != 0.0f) || (var_v0 = 3, (M2C_FIELD(arg0, s32 *, 0x114) != 0))) {
            goto block_10;
        }
        if (M2C_FIELD(arg0, f32 *, 0x110) == 0.0f) {
            M2C_FIELD(arg0, s32 *, 0xF0) = 0;
        } else {
            var_v0 = 1;
block_10:
            M2C_FIELD(arg0, s32 *, 0xF0) = var_v0;
        }
    }
    switch (M2C_FIELD(arg0, s32 *, 0xF0)) {         /* irregular */
    case 2:
        M2C_FIELD(arg0, f32 *, 0x138) = 3.4028235e38f;
        M2C_FIELD(arg0, f32 *, 0x130) = GRandInRange(M2C_FIELD(arg0, f32 *, 0xF8), M2C_FIELD(arg0, f32 *, 0xFC));
        if (M2C_FIELD(arg0, s32 *, 0x114) == 0) {
block_22:
            if (GRandInRange(0.0f, 1.0f) <= M2C_FIELD(arg0, f32 *, 0x104)) {
                PauseEmitter__FP7EMITTERf(arg0, GRandInRange(M2C_FIELD(arg0, f32 *, 0x108), M2C_FIELD(arg0, f32 *, 0x10C)));
            }
        } else {
block_21:
            PauseEmitterIndefinite__FP7EMITTER(arg0);
        }
        break;
    case 3:
        M2C_FIELD(arg0, f32 *, 0x138) = 3.4028235e38f;
        M2C_FIELD(arg0, f32 *, 0x130) = (f32) (GRandInRange(M2C_FIELD(arg0, f32 *, 0xF8), M2C_FIELD(arg0, f32 *, 0xFC)) * 60.0f);
        if (M2C_FIELD(arg0, s32 *, 0x114) != 0) {
            goto block_21;
        }
        goto block_22;
    default:
        M2C_FIELD(arg0, f32 *, 0x134) = 1.0f;
        M2C_FIELD(arg0, f32 *, 0x138) = 1.0f;
        M2C_FIELD(arg0, f32 *, 0x130) = GRandInRange(M2C_FIELD(arg0, f32 *, 0xF8), M2C_FIELD(arg0, f32 *, 0xFC));
        break;
    }
    temp_a0 = M2C_FIELD(arg0, s32 **, 0xE4);
    M2C_FIELD(arg0, f32 *, 0x13C) = 1.0f;
    if (M2C_FIELD(temp_a0, s32 *, 0x10) == 1) {
        temp_a0_2 = M2C_FIELD(temp_a0, s8 **, 0x30);
        if (*M2C_FIELD(temp_a0, s32 **, 8) != 0) {
            var_f1 = fabsf(M2C_FIELD(temp_a0_2, f32 *, 0x10) - M2C_FIELD(temp_a0_2, f32 *, 0));
            temp_f2 = fabsf(M2C_FIELD(temp_a0_2, f32 *, 0x14) - M2C_FIELD(temp_a0_2, f32 *, 4));
            temp_f0 = fabsf(M2C_FIELD(temp_a0_2, f32 *, 0x18) - M2C_FIELD(temp_a0_2, f32 *, 8));
            if (!(temp_f2 < var_f1) || !(temp_f0 < var_f1)) {
                var_f1 = temp_f0;
                if (temp_f0 < temp_f2) {
                    var_f1 = temp_f2;
                }
            }
            M2C_FIELD(arg0, f32 *, 0x140) = (f32) (var_f1 * 0.5f);
        }
        if (M2C_FIELD(arg0, s32 *, 0x100) != 0) {
            temp_f4 = M2C_FIELD(temp_a0_2, f32 *, 8);
            if (M2C_FIELD(arg0, f32 *, 0x110) != 0.0f) {
                var_f3 = 0.000001f;
                var_f1_2 = M2C_FIELD(temp_a0_2, f32 *, 0x18) - temp_f4;
                var_f0 = (M2C_FIELD(temp_a0_2, f32 *, 0x10) - M2C_FIELD(temp_a0_2, f32 *, 0)) * (M2C_FIELD(temp_a0_2, f32 *, 0x14) - M2C_FIELD(temp_a0_2, f32 *, 4));
            } else {
                var_f0 = M2C_FIELD(temp_a0_2, f32 *, 0x14) - M2C_FIELD(temp_a0_2, f32 *, 4);
                var_f3 = 0.0001f;
                var_f1_2 = M2C_FIELD(temp_a0_2, f32 *, 0x18) - temp_f4;
            }
            M2C_FIELD(arg0, f32 *, 0x13C) = (f32) (var_f0 * var_f1_2 * var_f3);
        }
    }
    temp_a2 = M2C_FIELD(arg0, s32 *, 0x118);
    if (temp_a2 != -1) {
        var_s2 = (s8 *)(PloFindSwObject_thunk(&B_003DD490, 5, temp_a2, 0));
        if (var_s2 == NULL) {
            var_s2 = (s8 *)(PloNew(0x1D, 0, M2C_FIELD(arg0, s32 *, 0x118), -1));
            temp_v0 = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(arg0, s32 **, 0xE4), 0x100, 0x10);
            M2C_FIELD(var_s2, s32 **, 0xE4) = temp_v0;
            *temp_v0 = 1;
            temp_a1 = M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xE4), s32 **, 8);
            if (*temp_a1 != 0) {
                M2C_FIELD(M2C_FIELD(var_s2, s32 **, 0xE4), s32 **, 8) = PvAllocSwCopyImpl__FiPv(sp, temp_a1, 0x14, 0x10);
                M2C_FIELD(M2C_FIELD(var_s2, s32 **, 0xE4), s32 *, 0x20) = -1;
                *M2C_FIELD(M2C_FIELD(var_s2, s32 **, 0xE4), s32 **, 8) = 0;
            }
            M2C_FIELD(var_s2, s32 *, 0xF0) = (s32) M2C_FIELD(arg0, s32 *, 0xF0);
            M2C_FIELD(var_s2, s32 *, 0xF4) = (s32) M2C_FIELD(arg0, s32 *, 0xF4);
            s32 vu_3;
            asm volatile("ldl %0, 0xff(%1)" : "=r"(vu_3) : "r"(arg0));
            s32 vu_4;
            asm volatile("ldr %0, 0xf8(%1)" : "=r"(vu_4) : "r"(arg0), "0"(vu_3));
            temp_v0_2 = vu_4;
            asm volatile("sdl %0, 0xff(%1)" : : "r"(temp_v0_2), "r"(var_s2));
            asm volatile("sdr %0, 0xf8(%1)" : : "r"(temp_v0_2), "r"(var_s2));
            M2C_FIELD(var_s2, s32 *, 0x100) = (s32) M2C_FIELD(arg0, s32 *, 0x100);
            M2C_FIELD(var_s2, f32 *, 0x104) = (f32) M2C_FIELD(arg0, f32 *, 0x104);
            s32 vu_5;
            asm volatile("ldl %0, 0x10f(%1)" : "=r"(vu_5) : "r"(arg0));
            s32 vu_6;
            asm volatile("ldr %0, 0x108(%1)" : "=r"(vu_6) : "r"(arg0), "0"(vu_5));
            temp_v0_3 = vu_6;
            asm volatile("sdl %0, 0x10f(%1)" : : "r"(temp_v0_3), "r"(var_s2));
            asm volatile("sdr %0, 0x108(%1)" : : "r"(temp_v0_3), "r"(var_s2));
            M2C_FIELD(var_s2, f32 *, 0x110) = (f32) M2C_FIELD(arg0, f32 *, 0x110);
            M2C_FIELD(var_s2, s32 *, 0x114) = (s32) M2C_FIELD(arg0, s32 *, 0x114);
            func_001A6CA8(var_s2, 1);
            temp_s0 = M2C_FIELD(var_s2, s8 **, 0xC);
            temp_s0_2 = temp_s0 + 0xF0;
            temp_s1 = var_s2 + M2C_FIELD(temp_s0, s16 *, 0xF0);
            M2C_FIELD(temp_s0_2, M2C_UNK (**)(s8 *, s32), 4)(temp_s1, PmatLoWorld(arg0));
        }
        M2C_FIELD(arg0, s32 *, 0xE0) = 0;
        AppendDlEntry(var_s2 + 0x11C, arg0);
        temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x40);
        if ((temp_a0_3 ^ 1) & 1) {
            *(s32 *)temp_a0_3 = (s32) (*(s32 *)temp_a0_3 & ~2);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) (temp_a0_3 & ~2);
    }
}
}
