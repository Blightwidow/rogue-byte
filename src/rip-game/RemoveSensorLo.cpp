typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 PentryFindSensorLo(s8 *);
void SetSensorEntryState(s8 *, s32, M2C_UNK);
void memmove(s32, s32, s32);

void RemoveSensorLo(s8 *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = PentryFindSensorLo(arg0);
    if (temp_v0 != 0) {
        SetSensorEntryState(arg0, temp_v0, 0);
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0xFC) - 1;
        M2C_FIELD(arg0, s32 *, 0xFC) = temp_v0_2;
        memmove(temp_v0, temp_v0 + 0x10, ((s32) ((arg0 + ((temp_v0_2 * 0x10) + 0x100)) - temp_v0) >> 4) * 0x10);
    }
}

}
