typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK InferExpl(s8 *, s8 *);                  /* extern */
M2C_UNK SetSoCnstrForce(s8 *, M2C_UNK);           /* extern */
M2C_UNK SetSoCnstrTorque(s8 *, M2C_UNK);          /* extern */
M2C_UNK SetSoNoXpsAll(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_001A58D0(s8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_001CB518();                            /* extern */

void Bomb_OnPoolClaim(s8 *arg0) {
    func_001CB518();
    M2C_FIELD(arg0, s32 *, 0x174) = 0;
    M2C_FIELD(arg0, f32 *, 0x154) = 3.4028235e38f;
    InferExpl(arg0, arg0);
    SetSoCnstrForce(arg0, 0);
    SetSoCnstrTorque(arg0, 0);
    SetSoNoXpsAll(arg0, 0);
    M2C_FIELD(arg0, s32 *, 0x1E8) = 0;
    func_001A58D0(arg0, 0, 0xF);
}

}
