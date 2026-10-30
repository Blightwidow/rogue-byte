typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RetractAsega {
    /* 0x00 */ s8 *sp0;                           /* inferred */
    /* 0x04 */ char pad4[0x5C];
};                                                  /* size = 0x60 */
s32 FAsegaGone(...);                             /* extern */
M2C_UNK FreeAct(s8 *);                            /* extern */
M2C_UNK HandleAsegaEvent(s8 *, f32 *);            /* extern */
M2C_UNK PostLoMessage(s8 *, M2C_UNK, s8 *);     /* extern */
M2C_UNK RemoveDlEntry(M2C_UNK *, s8 *);           /* extern */
M2C_UNK RemoveXfAct(s32, s32, s8 *);              /* extern */
M2C_UNK SetAsegaHandsOff(s8 *, M2C_UNK);          /* extern */
M2C_UNK VirtualRefPtr_Assign(s8 *, M2C_UNK);      /* extern */
M2C_UNK func_0012CE70(s8 *);                      /* extern */
extern M2C_UNK B_003E1218;
void RetractAsega(s8 *arg0) {
    s8 *sp0;
    f32 *temp_a1;
    s32 var_a0;
    s32 var_v1;
    s8 *temp_a3;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    s8 *temp_v0_7;
    s8 *var_a2;
    s8 *var_s1;
    s8 *var_s1_2;
    if (FAsegaGone() == 0) {
        sp0 = arg0;
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
        var_v1 = M2C_FIELD(arg0, s32 *, 0x54);
loop_6:
        if (var_v1 < M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0xA8)) {
            temp_a1 = (f32 *)(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0xAC) + (var_v1 * 0x10));
            *temp_a1 = M2C_FIELD(arg0, f32 *, 0x1C);
            HandleAsegaEvent(arg0, temp_a1);
            if (FAsegaGone(arg0) != 0) {
                temp_v0_2 = M2C_FIELD(sp0, s8 **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *), 0x14)(sp0 + M2C_FIELD(temp_v0_2, s16 *, 0x10), sp0);
            } else {
                var_v1 = M2C_FIELD(arg0, s32 *, 0x54) + 1;
                M2C_FIELD(arg0, s32 *, 0x54) = var_v1;
                goto loop_6;
            }
        } else {
            SetAsegaHandsOff(arg0, 0);
            RemoveDlEntry(&B_003E1218, arg0);
            RemoveDlEntry((M2C_UNK *)(M2C_FIELD(arg0, s8 **, 0x14) + 0x50), arg0);
            var_s1 = M2C_FIELD(arg0, s8 **, 0x34);
            if (var_s1 != NULL) {
                var_a0 = M2C_FIELD(var_s1, s32 *, 4);
loop_11:
                temp_s0 = M2C_FIELD(var_s1, s8 **, 0x28);
                RemoveXfAct(var_a0, M2C_FIELD(var_s1, s32 *, 8), var_s1);
                FreeAct(var_s1);
                var_s1 = temp_s0;
                if (var_s1 != NULL) {
                    var_a0 = M2C_FIELD(var_s1, s32 *, 4);
                    goto loop_11;
                }
            }
            var_s1_2 = M2C_FIELD(arg0, s8 **, 0x38);
            M2C_FIELD(arg0, s8 **, 0x34) = NULL;
            if (var_s1_2 != NULL) {
                var_a2 = M2C_FIELD(var_s1_2, s8 **, 8);
loop_16:
                temp_v0_3 = M2C_FIELD(var_a2, s8 **, 0xC);
                temp_s0_2 = M2C_FIELD(var_s1_2, s8 **, 0x10);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s32, s8 *), 0x16C)(var_a2 + M2C_FIELD(temp_v0_3, s16 *, 0x168), M2C_FIELD(var_s1_2, s32 *, 0xC), var_a2);
                func_0012CE70(var_s1_2);
                var_s1_2 = temp_s0_2;
                if (var_s1_2 != NULL) {
                    var_a2 = M2C_FIELD(var_s1_2, s8 **, 8);
                    goto loop_16;
                }
            }
            M2C_FIELD(arg0, s8 **, 0x38) = NULL;
            VirtualRefPtr_Assign(arg0 + 0x5C, 0);
            temp_v0_4 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0x18), 3, 0, 0);
            temp_a3 = M2C_FIELD(arg0, s8 **, 0x18);
            if (temp_a3 != NULL) {
                temp_v0_5 = M2C_FIELD(temp_a3, s8 **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK, s8 *, s8 *), 0x2C)(temp_a3 + M2C_FIELD(temp_v0_5, s16 *, 0x28), 2, arg0, temp_a3);
            }
            PostLoMessage(arg0, 2, arg0);
            temp_v0_6 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_6, M2C_UNK (**)(s8 *), 0x14)(arg0 + M2C_FIELD(temp_v0_6, s16 *, 0x10));
            temp_v0_7 = M2C_FIELD(sp0, s8 **, 0xC);
            M2C_FIELD(temp_v0_7, M2C_UNK (**)(s8 *, s8 *), 0x14)(sp0 + M2C_FIELD(temp_v0_7, s16 *, 0x10), sp0);
        }
    }
}
}
