typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateSwCallbacks {
    /* 0x00 */ s16 sp0;                             /* inferred */
    /* 0x02 */ u16 sp2;                             /* inferred */
    /* 0x04 */ u16 sp4;                             /* inferred */
    /* 0x06 */ char pad6[0x7A];
};                                                  /* size = 0x80 */
#define sp0 (*(s16 *)(sp + 0x00))
#define sp2 (*(u16 *)(sp + 0x02))
#define sp4 (*(u16 *)(sp + 0x04))
M2C_UNK CFrame_DeletingDestructor(s32 *, M2C_UNK);  /* extern */
M2C_UNK CPairPtr_Destructor(s32 *, M2C_UNK);        /* extern */
M2C_UNK CRef_Destruct(s32 *);                       /* extern */
M2C_UNK ClearSl(s32);                               /* extern */
M2C_UNK EvalScriptCall(s32 *, s32 *, s32, M2C_UNK); /* extern */
s32 FIsSlEmpty(s32);                                /* extern */
M2C_UNK FreeSlotheapPv(s32 *, s32 *);               /* extern */
s32 PframeNew(s32 *);                               /* extern */
M2C_UNK RemoveSlEntry(s32 *, s32 *);                /* extern */
M2C_UNK UnlinkPairNode(s32 *);                      /* extern */
M2C_UNK func_00257058(s8 *, s32);                 /* extern */
extern s32 B_004520A8;
extern f32 g_2dded0;
void UpdateSwCallbacks(s32 *arg0) {
    s32 saved_reg_s2;
    s8 sp[0x10] __attribute__((aligned(16)));
    M2C_UNK temp_v0;
    s16 var_v0;
    s32 *temp_s0;
    s32 *temp_s0_2;
    s32 *temp_s1;
    s32 *temp_s1_2;
    s32 *var_a0;
    s32 *var_s1;
    s32 temp_s4;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s64 var_a3;
    s64 var_s2;
    var_s2 = saved_reg_s2;
    temp_s4 = (s32)(arg0 + 0x3CA8);
loop_10:
    if (FIsSlEmpty(temp_s4) == 0) {
        var_s1 = M2C_FIELD(arg0, s32 **, 0x3CA8);
        ClearSl(temp_s4);
        if (var_s1 != NULL) {
            do {
                s32 vu_1;
                asm volatile("ldl %0, 0xb(%1)" : "=r"(vu_1) : "r"(var_s1));
                s32 vu_2;
                asm volatile("ldr %0, 0x4(%1)" : "=r"(vu_2) : "r"(var_s1), "0"(vu_1));
                temp_v0 = vu_2;
                asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_v0), "r"(sp));
                asm volatile("sdr %0, (%1)" : : "r"(temp_v0), "r"(sp));
                if ((s16) sp2 >= 0) {
                    var_s2 = M2C_FIELD((((s16) sp2 * 8) + *(s32 *)(M2C_FIELD(var_s1, s32 *, 0) + (s16) sp4)), s64 *, -8);
                    var_a3 = var_s2 >> 0x20;
                } else {
                    var_a3 = (s64) (s32) sp4;
                }
                if ((s16) sp2 >= 0) {
                    var_v0 = (s16) (var_s2 & 0xFFFF) + sp0;
                } else {
                    var_v0 = sp0;
                }
                ((M2C_UNK (*)(s32, s32, s16, s64)) var_a3)(M2C_FIELD(var_s1, s32 *, 0) + var_v0, M2C_FIELD(var_s1, s32 *, 0xC), (s16) sp2, var_a3);
                temp_s0 = M2C_FIELD(var_s1, s32 **, 0x10);
                FreeSlotheapPv(arg0 + 0x3C90, var_s1);
                var_s1 = temp_s0;
            } while (var_s1 != NULL);
        }
        goto loop_10;
    }
    temp_s1 = M2C_FIELD(arg0, s32 **, 0x39F0);
    if ((temp_s1 != NULL) && !(g_2dded0 < M2C_FIELD(temp_s1, f32 *, 0))) {
        var_a0 = M2C_FIELD(temp_s1, s32 **, 4);
loop_16:
        M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x39F0), s32 *, 0xC) = -1;
        if (var_a0 != NULL) {
            EvalScriptCall(var_a0, M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x39F0), s32 **, 8), *var_a0, 0);
        } else {
            func_00257058(sp, PframeNew(var_a0));
            EvalScriptCall(arg0, M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x39F0), s32 **, 8), (s32) sp0, 0);
            if ((s32 *) sp0 != NULL) {
                temp_v0_2 = *(s32 *) sp0 - 1;
                *(s32 *) sp0 = temp_v0_2;
                if (temp_v0_2 == 0) {
                    CFrame_DeletingDestructor((s32 *) sp0, 3);
                }
            }
        }
        RemoveSlEntry(arg0 + 0x39F0, M2C_FIELD(arg0, s32 **, 0x39F0));
        temp_s0_2 = M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x39F0), s32 **, 8);
        temp_v0_3 = *temp_s0_2 - 1;
        *temp_s0_2 = temp_v0_3;
        if ((temp_v0_3 == 0) && (temp_s0_2 != NULL)) {
            CPairPtr_Destructor(temp_s0_2 + 0x10, 2);
            CRef_Destruct(temp_s0_2 + 8);
            UnlinkPairNode(temp_s0_2);
            FreeSlotheapPv(&B_004520A8, temp_s0_2);
        }
        FreeSlotheapPv(arg0 + 0x39FC, M2C_FIELD(arg0, s32 **, 0x39F0));
        temp_s1_2 = M2C_FIELD(arg0, s32 **, 0x39F0);
        if (temp_s1_2 != NULL) {
            if (!(g_2dded0 < M2C_FIELD(temp_s1_2, f32 *, 0))) {
                var_a0 = M2C_FIELD(temp_s1_2, s32 **, 4);
                goto loop_16;
            }
        }
    }
}
}
