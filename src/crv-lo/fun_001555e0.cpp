typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void func_00155788(void *, M2C_UNK);
s32 func_00155868(void *);
void func_001EEF70();
void func_00208540(void *, s32);

void func_001555E0(void *arg0) {
    void *temp_v0;

    func_001EEF70();
    func_00208540(M2C_FIELD(arg0, void **, 0x10), M2C_FIELD(arg0, s32 *, 0x38));
    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    if ((M2C_FIELD(temp_v0, s32 *, 0x1018) - M2C_FIELD(temp_v0, s32 *, 0x33C)) >= 0x5A) {
        M2C_FIELD(arg0, s32 *, 0x3C) = func_00155868(arg0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_00155788(arg0, 0);
        return;
    }
    func_00155788(arg0, 1);
}

}
