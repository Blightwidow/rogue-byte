typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_001F4DA8(s8 *, s32, s8 *);         /* extern */
void func_001F5988(s8 *, s32);                            /* extern */

void NotifyVehicleXpEnded(s8 *arg0, s32 arg1) {
    struct E { u8 b[0x60]; };
    func_001F5988(arg0, arg1);
    for (s32 i = 0; i < M2C_FIELD(arg0, s32 *, 0x190); i++) {
        func_001F4DA8(arg0, arg1, (s8 *)&((E *)(arg0 + 0x1A8))[i]);
    }
}

}
