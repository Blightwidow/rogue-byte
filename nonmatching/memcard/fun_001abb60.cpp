typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 CheckCardStatus();                              /* extern */
s32 CreateSaveDirectory(s8 *);                    /* extern */
s32 WriteSaveSlot(s8 *, s32);                     /* extern */
M2C_UNK func_001ACC38(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK B_002E6550;

s32 func_001ABB60(s8 *arg0) {
    s32 var_s0;
    s32 var_v0;

    var_s0 = CheckCardStatus();
    if ((var_s0 == 0) && (var_s0 = CreateSaveDirectory(arg0), (var_s0 == 0))) {
        var_s0 = WriteSaveSlot(arg0, M2C_FIELD(arg0, s32 *, 0xFD50));
        var_v0 = var_s0;
        if (var_s0 != 0) {
            goto block_4;
        }
    } else {
block_4:
        func_001ACC38(&B_002E6550, 3);
        var_v0 = var_s0;
    }
    return var_v0;
}

}
