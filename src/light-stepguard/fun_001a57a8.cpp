typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A57A8 {
    /* 0x00 */ s32 sp0;                             /* inferred */
    /* 0x04 */ s32 *sp4;                            /* inferred */
    /* 0x08 */ char pad8[0x28];
};                                                  /* size = 0x30 */
M2C_UNK RemoveDlEntry(s32, s8 *);                 /* extern */
M2C_UNK func_001A5448(s32, s8 *, s32 **);         /* extern */
struct Buf1A57A8 { s32 first; s32 *second; s32 pad[2]; };
void func_001A57A8(s8 *arg0) {
    Buf1A57A8 buf;
    func_001A5448(M2C_FIELD(arg0, s32 *, 0x10), (s8 *)&buf, &buf.second);
    if (*buf.second == (s32)arg0) {
        *buf.second = M2C_FIELD(arg0, s32 *, 0x24);
    }
    RemoveDlEntry(buf.first, arg0);
}
}
