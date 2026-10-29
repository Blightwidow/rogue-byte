typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A6CA8 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK ReinsertSwRoot(M2C_UNK *, s32, u64);        /* extern */
extern M2C_UNK B_003DD490;
extern struct { int x; } B_003DD490_t;
struct S6CA8 { char pad[0x10]; s32 field10; s32 field14; char pad18[0x10]; u64 flags; };
void func_001A6CA8(S6CA8 *self, s32 arg1) {
    u64 flags = self->flags;
    if (arg1 == ((s64) (flags << 8) >> 0x3C)) return;
    flags = (flags & ~(0xFL << 0x34)) | ((u64) (arg1 & 0xF) << 0x34);
    self->flags = flags;
    if (self->field10 != 0) return;
    if ((int)(flags >> 0x3C) & 1) {
        s32 key = self->field14;
        ReinsertSwRoot(&B_003DD490, key, flags);
    }
}
}
