typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AddImage__4GIFSi {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
struct Vt167150 { char pad[8]; s16 adjust; s16 pad2; void (*fn)(s8 *, s32); };
struct Gif167150 { char pad[0xC]; u64 *cursor; char pad10[8]; Vt167150 *stream; };
void AddImage__4GIFSi(Gif167150 *self, s32 arg1) {
    self->stream->fn((s8 *) self + self->stream->adjust, 0);
    u64 *cursor = self->cursor;
    self->cursor = cursor + 2;
    cursor[0] = arg1 | (0x8000L << 0x2C);
    cursor[1] = 0;
}
}
