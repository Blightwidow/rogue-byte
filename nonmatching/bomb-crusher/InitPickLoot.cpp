typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitPickLoot {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK InitSo();                                   /* extern */
extern s128 RO_002A2DE0;
void InitPickLoot(s8 *arg0) {
    s32 temp_a2;
    InitSo();
    temp_a2 = M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x184) = -1;
    M2C_FIELD(arg0, s128 *, 0x170) = (s128) RO_002A2DE0;
    if ((temp_a2 ^ 1) & 1) {
        *(s32 *)temp_a2 = (s32) (*(s32 *)temp_a2 | 2);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) (temp_a2 | 2);
}
}
