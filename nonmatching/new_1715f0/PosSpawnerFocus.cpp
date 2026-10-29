typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s128 PosLoWorld(s32);                               /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD490;

s128 PosSpawnerFocus(void) {
    if (PpoSwFocusBase(&B_003DD490) == 0) {
        return M2C_FIELD(&B_002DDF40, s128 *, 0x90);
    }
    PosLoWorld(PpoSwFocusBase(&B_003DD490));
}

}
