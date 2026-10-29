typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_OnAmbVoicePolled {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK SetAmbGrf(s64, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK StopAmb(s64, M2C_UNK);                      /* extern */
void OnAmbVoicePolled(s32 arg0, s64 arg1) {
    s64 temp_s0;
    s8 *temp_v0;
    temp_s0 = (s64) (arg1 << 0x20) >> 0x20;
    if (arg0 == 0) {
        StopAmb(temp_s0, 0);
    } else {
        SetAmbGrf(temp_s0, 0x400, 0x400);
    }
    temp_v0 = M2C_FIELD(temp_s0, s8 **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32), 0x14)(temp_s0 + M2C_FIELD(temp_v0, s16 *, 0x10));
}
}
