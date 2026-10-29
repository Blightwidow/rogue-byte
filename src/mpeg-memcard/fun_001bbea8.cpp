typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void SetSoCnstrForce(void *, M2C_UNK);
void SetSoCnstrTorque(void *, M2C_UNK);
void StepStgSwitch(void *, M2C_UNK);
s32 func_001CB518();

void func_001BBEA8(void *arg0) {
    func_001CB518();
    StepStgSwitch(arg0, 0x609);
    if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
        SetSoCnstrForce(arg0, 1);
        SetSoCnstrTorque(arg0, 1);
    }
}

}
