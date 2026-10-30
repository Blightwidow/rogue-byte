typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0014A2A0 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 FGoalAnimDone(s32);                             /* extern */
s32 FGoalReactDone(s32);                            /* extern */
s32 GoalFollowCrv_FAtEnd(s32);                      /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
s32 PsenseFindNotice(s32, s32, M2C_UNK);            /* extern */
s32 func_0014A478(s8 *);                          /* extern */
M2C_UNK func_0014A4D0(s8 *);                      /* extern */
s32 func_0014AA30(s8 *);                          /* extern */
M2C_UNK func_0014AD70(s8 *);                      /* extern */
M2C_UNK func_0014AE38(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8(s8 *);                          /* extern */
s32 func_00209098(s32);                             /* extern */
extern M2C_UNK B_003DD490;
void func_0014A2A0(s8 *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    u32 temp_s1;
    func_001EEF98();
    func_0014A4D0(arg0);
loop_24:
    if (func_001EF0A8(arg0) == 0) {
        temp_s1 = M2C_FIELD(arg0, u32 *, 0x30);
        switch (temp_s1) {
        case 0:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) == 0) {
                if (func_0014A478(arg0) == 0) {
                    temp_v0 = func_0014AA30(arg0);
                    M2C_FIELD(arg0, s32 *, 0x40) = temp_v0;
                    if (temp_v0 == M2C_FIELD(arg0, s32 *, 0x3C)) {
                        temp_v0_2 = PsenseFindNotice(M2C_FIELD(arg0, s32 *, 0x10), PpoSwFocusBase(&B_003DD490), 0);
                        M2C_FIELD(arg0, s32 *, 0x44) = temp_v0_2;
                        if (temp_v0_2 != 0) {
                            func_0014AE38(arg0, 3);
                        }
                    } else {
                        func_0014AD70(arg0);
                    }
                } else {
block_11:
                    func_0014AE38(arg0, 2);
                }
            } else {
block_17:
                func_0014AE38(arg0, 4);
            }
            break;
        case 1:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) == 0) {
                if (func_0014A478(arg0) != 0) {
                    goto block_11;
                }
                if (GoalFollowCrv_FAtEnd(M2C_FIELD(arg0, s32 *, 0x18)) == 0) {
                    PsenseFindNotice(M2C_FIELD(arg0, s32 *, 0x10), PpoSwFocusBase(&B_003DD490), 0);
                } else {
block_20:
                    func_0014AE38(arg0, 0);
                }
            } else {
                goto block_17;
            }
            break;
        case 2:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) == 0) {
                var_v0 = FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18));
block_19:
                if (var_v0 != 0) {
                    goto block_20;
                }
            } else {
                goto block_17;
            }
            break;
        case 3:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) != 0) {
                goto block_17;
            }
            var_v0 = FGoalReactDone(M2C_FIELD(arg0, s32 *, 0x18));
            goto block_19;
        case 4:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) == 0) {
                func_0014AE38(arg0, 0);
            }
            break;
        }
        if (temp_s1 != M2C_FIELD(arg0, u32 *, 0x30)) {
            goto loop_24;
        }
    }
}
}
