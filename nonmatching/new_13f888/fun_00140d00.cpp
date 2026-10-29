typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void func_00193DE8(s8 *);
void func_001991A0(s8 *);
void func_0019E950(s8 *);
void func_001F4FA8();

void func_00140D00(s8 *arg0) {
    func_001F4FA8();
    if (M2C_FIELD(arg0, s32 *, 0x2DC) != -1) {
        func_001991A0(arg0 + 0x2C0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x4CC) != -1) {
        func_00193DE8(arg0 + 0x4C0);
    }
    if (M2C_FIELD(arg0, s32 *, 0xF54) != -1) {
        func_0019E950(arg0 + 0xF50);
    }
}

}
