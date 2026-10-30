typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct Vt1B1030 { char p0[0x230]; s16 delta; s16 pad; void (*fn)(void *); };
extern "C" {
M2C_UNK ProjectSoTransform(s8 *);                 /* extern */

void ProjectSlotSoTransform(s8 *arg0) {
    s32 temp_v1;
    s8 *temp_a0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    Vt1B1030 *temp_v0_3;
    s8 *temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x220);
    if (temp_v1 < 4) {
 if (temp_v1 >= 2) {
        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0x58);
        temp_v0 = temp_v1_2 + 0xF0;
        M2C_FIELD(temp_v0, s32 *, 8) = 0;
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
        M2C_FIELD(temp_v1_2, s32 *, 0xF0) = 0;
        temp_a0 = M2C_FIELD(arg0, s8 **, 0x5C);
        temp_v0_2 = temp_a0 + 0xF0;
        M2C_FIELD(temp_v0_2, s32 *, 8) = 0;
        M2C_FIELD(temp_v0_2, s32 *, 4) = 0;
        M2C_FIELD(temp_a0, s32 *, 0xF0) = 0;
        temp_v0_3 = M2C_FIELD(arg0, Vt1B1030 **, 0xC);
        temp_v0_3->fn(arg0 + temp_v0_3->delta);
    }
    }
    ProjectSoTransform(arg0);
}

}
