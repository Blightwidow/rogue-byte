typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK SetJmpState(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetJtZapState(s8 *, M2C_UNK);                     /* extern */
M2C_UNK WarpZapToSafePoint();                       /* extern */

void func_001A2080(s8 *arg0) {
    s8 *temp_v0;

    if (*M2C_FIELD(arg0, s32 **, 0x10) > 0) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0x30);
        if (temp_v0 == NULL) {
            goto block_8;
        }
        if (!(M2C_FIELD(temp_v0, s64 *, 0x148) & (0x8000L << 0x12))) {
block_8:
            SetJmpState(M2C_FIELD(arg0, s32 *, 0) + 0x2C0, 0xB, 0);
            return;
        }
        WarpZapToSafePoint();
        return;
    }
    SetJtZapState(arg0, 8);
}

}
