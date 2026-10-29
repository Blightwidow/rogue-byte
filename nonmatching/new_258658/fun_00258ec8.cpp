typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00258EC8 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

s32 *PemitblipEnsureEmitter(s8 *);
void SetEmitterBlipmk(M2C_UNK);
extern s32 B_002DE750;

s32 *func_00258EC8(s8 *arg0, s32 arg1) {
    s32 * result;
    s32 *var_a0;

    if (arg1 == 1) {
        SetEmitterBlipmk(1);
        var_a0 = (s32 *)(M2C_FIELD(arg0, s32 *, 0xE4) + 0xC0);
    } else {
        var_a0 = PemitblipEnsureEmitter(arg0);
    }
    if (*var_a0 == 1) {
        { result = var_a0 + 0x30; goto done; }
    }
    { result = &B_002DE750; goto done; }
done:
    return result;
}

}
