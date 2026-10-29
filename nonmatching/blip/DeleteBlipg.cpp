typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_DeleteBlipg {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

M2C_UNK FreeSlotheapPv(s8 *, s32);                /* extern */
s32 PdlFromSwCid(M2C_UNK *, M2C_UNK);               /* extern */
M2C_UNK RemoveSlEntry(s32, s32);                    /* extern */
extern M2C_UNK B_003DD490;

void DeleteBlipg(s32 arg0) {
    RemoveSlEntry(PdlFromSwCid(&B_003DD490, 0x1C), arg0);
    FreeSlotheapPv((s8 *)(&B_003DD490 + 0x4070), arg0);
}

}
