typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void GoalFlinch_SetState(s8 *, M2C_UNK);       /* extern */
M2C_UNK ReplaceSwHitFx(M2C_UNK *, M2C_UNK, s128, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_00174B28();                            /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;

void func_0017A558(s8 *arg0) {
    func_00174B28();
    GoalFlinch_SetState(arg0, -1);
    ReplaceSwHitFx(&B_003DD490, -1, g_2a2dd0, 0, (s32)(M2C_FIELD(arg0, s8 **, 0x10) + 0x35C));
    return;
}

}
