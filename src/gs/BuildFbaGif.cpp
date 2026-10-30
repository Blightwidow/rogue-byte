typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_BuildFbaGif {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
M2C_UNK AddPrimPack__4GIFSiiUl(s8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(s8 *, s32, s32);  /* extern */
M2C_UNK EndPrim__4GIFSi(s8 *, M2C_UNK);           /* extern */
M2C_UNK PackAD__4GIFSll(s8 *, M2C_UNK, s32);      /* extern */
M2C_UNK __4GIFS(s8 *);                            /* extern */
void BuildFbaGif(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x30] __attribute__((aligned(16)));
    __4GIFS(sp);
    AllocStatic__4DMASiP2QW(sp, arg0, arg1);
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    PackAD__4GIFSll(sp, 0x4A, arg2);
    EndPrim__4GIFSi(sp, 1);
}
}
