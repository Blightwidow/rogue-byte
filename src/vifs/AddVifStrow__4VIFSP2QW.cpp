typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void AddVifStrow__4VIFSP2QW(s8 *arg0, s8 *arg1) {
    s32 *temp_a2;
    s32 *temp_a2_2;
    s32 *temp_a3;
    s32 *temp_v1;
    s32 *temp_a3_2;

    temp_v1 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) ((s8 *)temp_v1 + 4);
    *temp_v1 = 0x30000000;
    temp_a2 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) ((s8 *)temp_a2 + 4);
    *temp_a2 = M2C_FIELD(arg1, s32 *, 0);
    temp_a3 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) ((s8 *)temp_a3 + 4);
    *temp_a3 = M2C_FIELD(arg1, s32 *, 4);
    temp_a2_2 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) ((s8 *)temp_a2_2 + 4);
    *temp_a2_2 = M2C_FIELD(arg1, s32 *, 8);
    temp_a3_2 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) ((s8 *)temp_a3_2 + 4);
    *temp_a3_2 = M2C_FIELD(arg1, s32 *, 0xC);
}

}
