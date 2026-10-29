typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct Bytes8 { u8 b[8]; };
M2C_UNK InitSo();
extern s128 D_002BE7D0;
extern Bytes8 D_002BE7E0;
struct Obj17F090 { char pad0[0x40]; s32 flags; char pad44[0x13C]; s32 state; char pad184[0x1C]; s128 vec; Bytes8 bytes; };
void func_0017F090(Obj17F090 *self) {
    InitSo();
    self->state = 0xA;
    self->vec = D_002BE7D0;
    self->bytes = D_002BE7E0;
    s32 flags = self->flags;
    if ((flags ^ 1) & 1) {
        *(s32 *)flags = (s32) (*(s32 *)flags | 2);
    } else {
        self->flags = flags | 2;
    }
}
}
