typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void AddGuardSgs(s32, s32);
void GoalAnim_SetState(void *, M2C_UNK);
s32 PguardanimCurrent(s32);
void func_001EEF70();

void func_00174950(void *arg0) {
    s32 temp_v0;

    func_001EEF70();
    AddGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x3C));
    if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        temp_v0 = PguardanimCurrent(M2C_FIELD(arg0, s32 *, 0x10));
        M2C_FIELD(arg0, s32 *, 0x40) = temp_v0;
        if (temp_v0 == 0) {
            GoalAnim_SetState(arg0, 1);
            return;
        }
        goto block_4;
    }
block_4:
    GoalAnim_SetState(arg0, 0);
}

}
