typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0016E1A8 {
    /* 0x00 */ s32 sp0;                             /* inferred */
    /* 0x04 */ char pad4[0x2C];
};                                                  /* size = 0x30 */
#define sp0 (*(s32 *)(sp + 0x00))
M2C_UNK AddDmaCnt__4DMAS(s32);                      /* extern */
M2C_UNK AddVifMscal__4VIFSPv(s32, f32);         /* extern */
M2C_UNK EndDmaCnt__4DMAS(s32);                      /* extern */
M2C_UNK EnsureVu1Code__FP4VIFSPvT1(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK memset(s32, M2C_UNK, M2C_UNK);              /* extern */
extern M2C_UNK RO_0025E680;
extern M2C_UNK RO_00262320;
void func_0016E1A8(s32 arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    EnsureVu1Code__FP4VIFSPvT1(&RO_0025E680, &RO_00262320);
    AddDmaCnt__4DMAS(arg0);
    UnpackHelper__4VIFS3UPKiiPiPPUi(arg0, 0xD, 0xB, 0xA);
    memset(sp0, 0, 0x58);
    AddVifMscal__4VIFSPv(arg0, 0);
    EndDmaCnt__4DMAS(arg0);
}
}
