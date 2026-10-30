typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RunStgSwitchStage {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s8 *sp40;                          /* inferred */
    /* 0x44 */ char pad44[0x7C];
};                                                  /* size = 0xC0 */
M2C_UNK ApplyTaskStateRequests(M2C_UNK *, M2C_UNK, s32, s8 *); /* extern */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
M2C_UNK JoltCm(M2C_UNK *, s32);                     /* extern */
M2C_UNK OnDifficultyBreak(M2C_UNK *, M2C_UNK, s32, M2C_UNK); /* extern */
s8 *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s8 *); /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
M2C_UNK TriggerJoyRumbleRumk__FP3JOY4RUMKf(M2C_UNK *, s32, M2C_UNK); /* extern */
M2C_UNK func_001F6978(s8 *, s32);                 /* extern */
M2C_UNK func_001F69F8(s8 *, s32);                 /* extern */
M2C_UNK func_001F6AC8(s8 *, s32);                 /* extern */
M2C_UNK func_001F6B48(s8 *, s32);                 /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DE578;
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_003DD490;
void RunStgSwitchStage(s8 *arg0, s8 *arg1) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s8 *sp40;
    M2C_UNK (*var_v1)(s8 *);
    s16 var_a0;
    s32 var_s3;
    s32 var_v0;
    u32 temp_v1;
    s8 *temp_s0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v1_2;
    s8 *var_s1;
    s8 *var_s5;
    var_s3 = 0;
    var_s5 = NULL;
    if (M2C_FIELD(arg1, s32 *, 8) > 0) {
loop_2:
        temp_s0 = (s8 *)(M2C_FIELD(arg1, s32 *, 0xC) + (var_s3 * 8));
        if ((((M2C_FIELD(arg0, s32 *, 0x158) <= 0) && (M2C_FIELD(arg1, s32 *, 4) > 0)) || !((0x3F >> M2C_FIELD(temp_s0, u32 *, 0)) & 1)) && ((var_s1 = NULL, (((0xC3 >> M2C_FIELD(temp_s0, u32 *, 0)) & 1) == 0)) || (var_s1 = PloFindSwObject_thunk(&B_003DD490, 1, M2C_FIELD(temp_s0, s32 *, 4), arg0), (var_s1 != NULL)))) {
            temp_v1 = M2C_FIELD(temp_s0, u32 *, 0);
            switch (temp_v1) {
            case 6:
                var_s5 = var_s1;
                break;
            case 0:
                temp_v0 = M2C_FIELD(var_s1, s8 **, 0xC);
                var_a0 = M2C_FIELD(temp_v0, s16 *, 0x40);
                var_v1 = M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *), 0x44);
block_12:
                var_v1(var_s1 + var_a0);
                break;
            case 1:
                temp_v0_2 = M2C_FIELD(var_s1, s8 **, 0xC);
                var_a0 = M2C_FIELD(temp_v0_2, s16 *, 0x48);
                var_v1 = M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *), 0x4C);
                goto block_12;
            case 2:
                func_001F6978(arg0, M2C_FIELD(temp_s0, s32 *, 4));
                break;
            case 3:
                func_001F69F8(arg0, M2C_FIELD(temp_s0, s32 *, 4));
                break;
            case 4:
                func_001F6AC8(arg0, M2C_FIELD(temp_s0, s32 *, 4));
                break;
            case 5:
                func_001F6B48(arg0, M2C_FIELD(temp_s0, s32 *, 4));
                break;
            case 7:
                if (FIsBasicDerivedFrom(var_s1, 0x1E) != 0) {
                    temp_v0_3 = M2C_FIELD(var_s1, s8 **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s8 *, s32, s8 *), 0x19C)(var_s1 + M2C_FIELD(temp_v0_3, s16 *, 0x198), sp, 1, (var_s5 != NULL) ? var_s5 : var_s1);
                }
                break;
            case 8:
                if (M2C_FIELD(arg0, s32 *, 0x168) & 2) {
                    JoltCm(&B_002DDF40, M2C_FIELD(temp_s0, s32 *, 4));
                }
                break;
            case 9:
                if (M2C_FIELD(arg0, s32 *, 0x168) & 4) {
                    TriggerJoyRumbleRumk__FP3JOY4RUMKf(&B_002DFC00, M2C_FIELD(temp_s0, s32 *, 4), 0x3E99999A);
                }
                break;
            case 10:
                if (M2C_FIELD(arg0, s32 *, 0x168) & 8) {
                    if (var_s5 != NULL) {
                        var_v0 = PosLoWorld(var_s5);
                    } else {
                        var_v0 = PosLoWorld(arg0);
                    }
                    s64 vu_1;
                    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(var_v0));
                    OnDifficultyBreak(&B_002DE578, vu_1, M2C_FIELD(temp_s0, s32 *, 4), -0x64);
                }
                break;
            case 11:
                temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                sp40 = temp_s0 + 4;
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x18), 4, 0, 1);
                break;
            case 12:
                ApplyTaskStateRequests(&B_002DEB30, 1, M2C_FIELD(temp_s0, s32 *, 4), arg0);
                break;
            }
        }
        var_s3 += 1;
        if (var_s3 < M2C_FIELD(arg1, s32 *, 8)) {
            goto loop_2;
        }
    }
}
}
