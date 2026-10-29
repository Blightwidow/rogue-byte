typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FGuardScriptWaiting(s8 *);
void func_001EEF98();

void UpdateGuardScriptBeh(s8 *arg0) {
    s8 *temp_a1;
    s8 *temp_v0;

    func_001EEF98();
    if (M2C_FIELD(arg0, s8 **, 0x38) != NULL) {
loop_1:
        if (FGuardScriptWaiting(arg0) == 0) {
            temp_a1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x38), s8 **, 0x18);
            M2C_FIELD(arg0, s8 **, 0x38) = temp_a1;
            if (temp_a1 != NULL) {
                temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *), 0x7C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x78), temp_a1);
                if (M2C_FIELD(arg0, s8 **, 0x38) != NULL) {
                    goto loop_1;
                }
            }
        }
    }
}

}
