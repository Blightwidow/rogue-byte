typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EndJumperFlight {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK RecalcSwOxfFilterForObject(M2C_UNK *, s8 *); /* extern */
M2C_UNK SetXfKind(s8 *, s32, M2C_UNK);            /* extern */
M2C_UNK func_0012E460(s8 *);                      /* extern */
extern M2C_UNK B_003DD490;
void EndJumperFlight(s8 *arg0) {
    s8 *temp_a0;
    s8 *temp_v1;
    if (M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        M2C_FIELD(arg0, s32 *, 0x60) = 0;
        if (M2C_FIELD(arg0, s32 *, 0x68) != 0) {
            func_0012E460(arg0 + 0x68);
            temp_a0 = M2C_FIELD(arg0, s8 **, 0x34);
            SetXfKind(temp_a0, M2C_FIELD(temp_a0, s32 *, 0x58), 2);
            temp_v1 = M2C_FIELD(arg0, s8 **, 0x34);
            M2C_FIELD(temp_v1, s64 *, 0x148) = (s64) (M2C_FIELD(temp_v1, s64 *, 0x148) & ~(s64)0x4000000);
            RecalcSwOxfFilterForObject(&B_003DD490, M2C_FIELD(arg0, s8 **, 0x34));
        }
    }
}
}
