typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00211348 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

s8 *PchzStringFromId(M2C_UNK *, s32);       /* extern */
s8 *strcpy(s8 *, s8 *);                           /* extern */
extern M2C_UNK B_003DD490;

struct T211348 { char pad[0xCC]; s32 ids[4]; };
void func_00211348(s8 *arg0, s32 arg1, T211348 *arg2) {
    strcpy(arg0, PchzStringFromId(&B_003DD490, arg2->ids[arg1]));
}

}
