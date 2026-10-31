typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s8 *); /* extern */
M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK PsmaApplySm(s8 *, s32, s32, s32);         /* extern */
extern M2C_UNK B_003DD490;

void PostSmLoad(s8 *arg0) {
    s8 *temp_a2;
    s8 *temp_v1;

    PostLoLoad();
    temp_a2 = M2C_FIELD(arg0, s8 **, 0x74);
    if (temp_a2 != NULL) {
        s32 found = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(temp_a2, s32 *, 0), arg0);
        temp_v1 = M2C_FIELD(arg0, s8 **, 0x74);
        PsmaApplySm(arg0, found, M2C_FIELD(temp_v1, s32 *, 4), M2C_FIELD(temp_v1, s32 *, 8));
    }
}

}
