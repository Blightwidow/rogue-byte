typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK CSo_LoadFromBrx();                          /* extern */
M2C_UNK ResolveSlotSoAsegs(s8 *);                 /* extern */
M2C_UNK SetXfKind(s8 *, s8 *, M2C_UNK);         /* extern */

void func_001B0CA8(s8 *arg0) {
    s8 *temp_v0;
    s8 *temp_v1;

    CSo_LoadFromBrx();
    SetXfKind(arg0, M2C_FIELD(arg0, s8 **, 0x58), 1);
    temp_v1 = M2C_FIELD(arg0, s8 **, 0x58);
    temp_v0 = temp_v1 + 0xF0;
    M2C_FIELD(temp_v0, s32 *, 8) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(temp_v1, s32 *, 0xF0) = 0;
    M2C_FIELD(arg0, s32 *, 0x1D4) = (s32) M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x5C), s16 *, 0x98);
    ResolveSlotSoAsegs(arg0);
}

}
