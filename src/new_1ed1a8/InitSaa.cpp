typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitSaa {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

void AppendSlEntry(M2C_UNK *, s8 *);
void InitSl(s32, s32);
s32 PrependSlEntry(M2C_UNK *, s8 *);
extern M2C_UNK B_003E159C;

void InitSaa(s8 *arg0, s8 *arg1) {
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(arg1, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg1, u16 *, 8);
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) M2C_FIELD(arg1, u16 *, 0xA);
    InitSl((int)(arg0 + 0x34), 0x10);
    if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        PrependSlEntry(&B_003E159C, arg0);
        return;
    }
    AppendSlEntry(&B_003E159C, arg0);
}

}
