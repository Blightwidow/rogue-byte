typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PpathVaultFlag {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s16 sp10;                            /* inferred */
    /* 0x12 */ char pad12[0x2E];
};                                                  /* size = 0x40 */
s32 IdCurrentLevel();                               /* extern */
s32 PpathConcatStack(f32, s8 *);                  /* extern */
s16 SymidFindSymtab(s8 *, M2C_UNK *);             /* extern */
s32 func_002109B8(s32, s16 *, s32, s16 *);          /* extern */
extern M2C_UNK B_003E0EA8;
s32 PpathVaultFlag(void) {
    s32 result;
    s8 sp[0x10] __attribute__((aligned(16)));
    s16 sp10;
    s32 temp_v0;
    temp_v0 = IdCurrentLevel();
    if (temp_v0 != -1) {
        sp10 = SymidFindSymtab((s8 *)(&B_003E0EA8 + 8), (M2C_UNK *)("fVault"));
        { result = PpathConcatStack(func_002109B8(temp_v0, &sp10, 1, &sp10), sp); goto done; }
    }
    { result = 0; goto done; }
done:
    return result;
}
}
