typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A2028 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
struct Continuation { long value; } __attribute__((packed));
s32 NewEmitter(int);
void SetEmitterUnpositioned(s32, int);
void SetJtZapState(s32, int);
void SetZapContinuation(s32, long);
extern Continuation RO_002A6790;
void func_001A2028(s32 arg0) {
    SetEmitterUnpositioned(NewEmitter(0x6A), 0);
    SetJtZapState(arg0, 6);
    SetZapContinuation(arg0, RO_002A6790.value);
}
}
