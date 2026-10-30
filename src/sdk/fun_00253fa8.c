typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
void func_0024FA38(s8 *, const char *);
int func_00252148(s8 *, int);
void func_00254488(s8 *);
void func_00253FA8(s8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x850) = func_00252148(arg0, 1);
    if (M2C_FIELD(arg0, s32 *, 0x850) != 0) {
        func_00254488(arg0);
        *(volatile u32 *)0x10002000 = 0x50000000;
        M2C_FIELD(arg0, s32 *, 0x82C) = 0x50000000;
        M2C_FIELD(arg0, s32 *, 0x828) = 1;
        func_00254488(arg0);
    }
    M2C_FIELD(arg0, s32 *, 0x854) = func_00252148(arg0, 1);
    if (M2C_FIELD(arg0, s32 *, 0x854) != 0) {
        func_00254488(arg0);
        *(volatile u32 *)0x10002000 = 0x58000000;
        M2C_FIELD(arg0, s32 *, 0x82C) = 0x50000000;
        M2C_FIELD(arg0, s32 *, 0x828) = 1;
        func_00254488(arg0);
    }
    if (func_00252148(arg0, 1) != 0) {
        func_0024FA38(arg0, "load_chroma_intra_quantizer_matrix == 1");
    }
    if (func_00252148(arg0, 1) != 0) {
        func_0024FA38(arg0, "load_chroma_non_intra_quantizer_matrix == 1");
    }
}
