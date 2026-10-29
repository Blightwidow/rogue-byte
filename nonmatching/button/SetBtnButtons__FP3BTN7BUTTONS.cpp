typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK TriggerBtn(s8 *);                         /* extern */
M2C_UNK UntriggerBtn(s8 *);                       /* extern */
extern f32 g_2dded0;

void SetBtnButtons__FP3BTN7BUTTONS(s8 *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_a0;
    s32 var_s1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x90);
    if (temp_v1 != arg1) {
        var_a0 = 0;
        if (temp_v1 == 0) {
            var_a0 = arg1 == 1;
        }
        var_s1 = 0;
        if (temp_v1 != -1) {
            var_s1 = arg1 == 0;
        }
        M2C_FIELD(arg0, f32 *, 0x94) = (f32) g_2dded0;
        M2C_FIELD(arg0, s32 *, 0x90) = arg1;
        if (var_a0 != 0) {
            TriggerBtn(arg0);
        }
        if (var_s1 != 0) {
            UntriggerBtn(arg0);
        }
    }
}

}
