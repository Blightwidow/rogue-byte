typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_HandlePoMessage {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

void HandleLoMessage();
void StopAmb(s32, f32);
void VirtualRefPtr_Assign(s32, M2C_UNK);

void HandlePoMessage(s8 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_s0;

    HandleLoMessage();
    if (arg1 == 5) {
        temp_s0 = (s32)(arg0 + 0x174);
        if (temp_s0 != 0) {
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x174);
            if (temp_a0 != 0) {
                StopAmb(temp_a0, 0);
                VirtualRefPtr_Assign(temp_s0, 0);
            }
        }
    }
}

}
