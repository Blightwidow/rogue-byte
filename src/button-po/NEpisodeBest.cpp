typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct CRef { s32 a; s32 value; s32 b; s32 c; };
extern "C" {
M2C_UNK CRef_Destruct(CRef *);
M2C_UNK func_001D8A38(CRef *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK RO_002A8A78;
s32 NEpisodeBest(void) {
    CRef ref;
    func_001D8A38(&ref, &RO_002A8A78, 0);
    s32 value = ref.value;
    CRef_Destruct(&ref);
    return value;
}
}
