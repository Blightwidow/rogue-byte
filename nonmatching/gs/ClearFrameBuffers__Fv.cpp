typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ClearFrameBuffers__Fv {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ M2C_UNK sp20;                        /* inferred */
    /* 0x20 */ char pad20[0x40];
};                                                  /* size = 0x60 */

M2C_UNK AddDmaEnd__4DMAS(s8 *);                   /* extern */
M2C_UNK AddDmaRefs__4DMASiP2QW(s8 *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(s8 *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK BlastAqwGifsBothFrames__FP2QW(M2C_UNK *);   /* extern */
M2C_UNK Detach__4DMASPiPP2QW(s8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK __4DMAS(s8 *);                            /* extern */
extern M2C_UNK B_002DF260;

void ClearFrameBuffers__Fv(void) {
    s8 sp[0x60] __attribute__((aligned(16)));
    M2C_UNK sp20;

    __4DMAS(sp);
    AllocStatic__4DMASiP2QW(sp, 2, &sp20);
    AddDmaRefs__4DMASiP2QW(sp, 0x25, &B_002DF260);
    AddDmaEnd__4DMAS(sp);
    Detach__4DMASPiPP2QW(sp, 0, 0);
    BlastAqwGifsBothFrames__FP2QW(&sp20);
}

}
