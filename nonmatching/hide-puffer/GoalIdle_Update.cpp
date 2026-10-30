typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GoalIdle_Update {
    /* 0x00 */ char pad0[0x80];
};                                                  /* size = 0x80 */
s32 FGuardScriptDone(s32);                          /* extern */
M2C_UNK GoalIdle_SetState(s8 *, M2C_UNK);         /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8(s8 *);                          /* extern */
s32 func_00209098(s32);                             /* extern */
extern f32 g_2dded0;
void GoalIdle_Update(s8 *arg0) {
    s32 temp_s1;
    s32 temp_s2;
    func_001EEF98();
    temp_s2 = func_00209098(M2C_FIELD(arg0, s32 *, 0x10));
loop_24:
    if (func_001EF0A8(arg0) == 0) {
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x38);
        switch (temp_s1) {                          /* irregular */
        case 1:
            if (temp_s2 == 0) {
                if (M2C_FIELD(arg0, f32 *, 0x34) < g_2dded0) {
                    GoalIdle_SetState(arg0, 0);
                }
            } else {
block_15:
                GoalIdle_SetState(arg0, 3);
            }
            break;
        case 2:
            if (temp_s2 != 0) {
                goto block_15;
            }
            break;
        case 0:
            if (temp_s2 != 0) {
                goto block_15;
            }
            if (!(M2C_FIELD(arg0, f32 *, 0x30) < g_2dded0)) {
                if (FGuardScriptDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
                    M2C_FIELD(arg0, s32 *, 0x40) = 0;
                    GoalIdle_SetState(arg0, 2);
                }
            } else {
block_21:
                GoalIdle_SetState(arg0, 1);
            }
            break;
        case 3:
            if (temp_s2 == 0) {
                if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
                    goto block_21;
                }
                GoalIdle_SetState(arg0, 2);
            }
            break;
        }
        if (M2C_FIELD(arg0, s32 *, 0x38) != temp_s1) {
            goto loop_24;
        }
    }
}
}
