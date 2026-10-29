typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AddVehicleWheel {};               /* size 0x0 */
struct Bytes8 { u8 bytes[8]; };
struct Wheel { s32 field0; char pad[0x1C]; f32 value; Bytes8 position; char pad2[0x34]; };
void AddVehicleWheel(s8 *arg0, s32 arg1, Bytes8 *arg2, f32 fparg0) {
    u32 count = M2C_FIELD(arg0, u32 *, 0x190);
    if (count < 8U) {
        M2C_FIELD(arg0, u32 *, 0x190) = count + 1;
        Wheel *wheel = (Wheel *)(arg0 + 0x1A0) + count;
        wheel->field0 = arg1;
        wheel->value = fparg0;
        wheel->position = *arg2;
    }
}
}
