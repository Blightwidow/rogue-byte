typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RunStgSwitch {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 FStgSwitchDone();                               /* extern */
s32 FStgSwitchInStageRange(s8 *);                 /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK RunStgSwitchStage(s8 *, s8 *);          /* extern */
M2C_UNK SpawnSwHitFx(s8 *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s8 *); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
void RunStgSwitch(s8 *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_4;
    s32 var_a0;
    s32 var_v0;
    s8 *temp_s2;
    s8 *temp_v0;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    if (FStgSwitchDone() == 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x16C);
        if (temp_a0 != PpoSwFocusBase(&B_003DD490)) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x170);
            if ((temp_v1 != 0x100) && (temp_v1 != 0x10000)) {
                var_v0 = 8;
                if (temp_v1 != 0x20000) {
                    if (temp_a0 == 0) {
                        M2C_FIELD(arg0, s32 *, 0x168) = 0;
                    } else if (FIsBasicDerivedFrom(temp_a0, 0x3B) == 0) {
                        M2C_FIELD(arg0, s32 *, 0x168) = 0;
                    } else {
                        goto block_14;
                    }
                } else {
                    goto block_15;
                }
            } else {
block_14:
                var_v0 = 8;
                goto block_15;
            }
        } else {
            var_v0 = 0xE;
block_15:
            M2C_FIELD(arg0, s32 *, 0x168) = var_v0;
        }
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x18), 0x10, 0, 0);
        if (!(M2C_FIELD(arg0, s32 *, 0x168) & 1)) {
            temp_a1 = M2C_FIELD(arg0, s32 *, 0x164);
            temp_s2 = (s8 *)(temp_a1 + (M2C_FIELD(arg0, s32 *, 0x15C) * 0x10));
            RunStgSwitchStage(arg0, (s8 *)(temp_a1 - 0x10));
            RunStgSwitchStage(arg0, temp_s2);
            temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x16C);
            if (temp_a0_2 != 0) {
                if (FIsBasicDerivedFrom(temp_a0_2, 0x38) != 0) {
                    if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x16C), 0x3C) != 0) {
                        goto block_20;
                    }
                } else {
                    goto block_21;
                }
            } else {
block_20:
block_21:
                s64 vu_1;
                asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(arg0)));
                SpawnSwHitFx((s8 *)(&B_003DD490 - 0x2B70), 0, vu_1, M2C_FIELD(arg0, s32 *, 0x16C));
            }
            if (M2C_FIELD(temp_s2, s32 *, 4) > 0) {
                temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x158) + 1;
                M2C_FIELD(arg0, s32 *, 0x158) = temp_v0_2;
                if (temp_v0_2 >= M2C_FIELD(temp_s2, s32 *, 4)) {
                    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x15C) + 1;
                    M2C_FIELD(arg0, s32 *, 0x158) = 0;
                    M2C_FIELD(arg0, s32 *, 0x15C) = temp_v0_3;
                    if (temp_v0_3 >= M2C_FIELD(arg0, s32 *, 0x160)) {
                        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                        M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x24)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x20), 0x10, arg0);
                        temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
                        M2C_FIELD(temp_v1_3, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x18), 5, 0, 0);
                        bevy_camera_follow_activity(&B_002DEB30, 0x11, arg0);
                    }
                }
            }
            if ((FStgSwitchInStageRange(arg0) != 0) && (M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x164) + (M2C_FIELD(arg0, s32 *, 0x15C) * 0x10)), s32 *, 4) <= 0)) {
                var_a0 = 0;
                if (M2C_FIELD(arg0, s32 *, 0x150) > 0) {
loop_30:
                    temp_v1_4 = var_a0 * 8;
                    var_a0 += 1;
                    M2C_FIELD((temp_v1_4 + M2C_FIELD(arg0, s32 *, 0x154)), s32 *, 4) = 0;
                    if (var_a0 < M2C_FIELD(arg0, s32 *, 0x150)) {
                        goto loop_30;
                    }
                }
            }
        }
    }
}
}
