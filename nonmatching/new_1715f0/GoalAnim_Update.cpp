typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FDoneAnimref(s32);                              /* extern */
M2C_UNK GoalAnim_SetState(s8 *, M2C_UNK);         /* extern */
M2C_UNK func_001EEF98();                            /* extern */

void GoalAnim_Update(s8 *arg0) {
    func_001EEF98();
loop_1:
    if ((M2C_FIELD(arg0, s32 *, 0x30) == 0) && (FDoneAnimref(M2C_FIELD(arg0, s32 *, 0x40)) != 0)) {
        GoalAnim_SetState(arg0, 1);
    }
    if (M2C_FIELD(arg0, s32 *, 0x30) != M2C_FIELD(arg0, s32 *, 0x30)) {
        goto loop_1;
    }
}

}
