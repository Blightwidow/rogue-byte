typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK DrainJtPower(f32);                     /* extern */
extern f32 D_FLT_002BD260;
extern f32 D_FLT_002BD264;

void DrainJtGadget(s32 *arg1) {
    s32 temp_a1;

    temp_a1 = *arg1;
    switch (temp_a1) {                              /* irregular */
    case 29:
        DrainJtPower(D_FLT_002BD260);
        return;
    case 42:
        DrainJtPower(D_FLT_002BD264);
        break;
    }
}

}
