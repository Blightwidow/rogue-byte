typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void RemoveLoHierarchy();
void SetVolbtnButtons(s8 *, M2C_UNK);

void RemoveVolbtn(s8 *arg0) {
    s8 *temp_v1;

    RemoveLoHierarchy();
    if ((u32) (M2C_FIELD(arg0, s32 *, 0x1C0) - 1) < 2U) {
        SetVolbtnButtons(arg0, 0);
        if (M2C_FIELD(arg0, s32 *, 0x2C8) != 0) {
            M2C_FIELD(arg0, s32 *, 0x2C0) = 0;
            temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 9, 0, 0);
        }
    }
}

}
