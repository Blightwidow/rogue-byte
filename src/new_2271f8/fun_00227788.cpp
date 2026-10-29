extern "C" {
typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

struct Bytes4_227788 {
    char value[4];
};

void func_002275B8(void *, s32);

void func_00227788(s8 *arg0) {
    char sp[0x10];

    M2C_FIELD(arg0, s32 *, 0) = -1;
    func_002275B8(sp, -1);
    *(struct Bytes4_227788 *) (arg0 + 4) = *(struct Bytes4_227788 *) sp;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}
}
