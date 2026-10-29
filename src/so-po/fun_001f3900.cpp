typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F3900 {};                 /* size 0x0 */
void func_001F3900(s8 *arg0) {
    s32 index;
    s8 *entry;
    s8 *source;
    for (index = 0; index < M2C_FIELD(arg0, s32 *, 0xE0); index++) {
        entry = M2C_FIELD(arg0, s8 **, 0xE4) + index * 0xB0;
        if (!(M2C_FIELD(entry, s64 *, 0x10) & (0x8000L << 0x23))) {
            source = M2C_FIELD(entry, s8 **, 0);
            M2C_FIELD(entry, s128 *, 0x20) = (s128) M2C_FIELD(source, s128 *, 0x40);
            M2C_FIELD(entry, s128 *, 0x30) = (s128) M2C_FIELD(source, s128 *, 0x50);
            M2C_FIELD(entry, s128 *, 0x40) = (s128) M2C_FIELD(source, s128 *, 0x60);
            M2C_FIELD(entry, s128 *, 0x50) = (s128) M2C_FIELD(source, s128 *, 0x70);
            M2C_FIELD(entry, s32 *, 0xAC) = (s32) M2C_FIELD(source, s32 *, 0xA4);
        }
    }
}
}
