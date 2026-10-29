typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Camobj_RemoveLoHierarchy {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

void RemoveLoHierarchy();
void RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *);
extern M2C_UNK B_002DDF40;

void Camobj_RemoveLoHierarchy(s8 *arg0) {
    RemoveLoHierarchy();
    if (M2C_FIELD(arg0, s32 *, 0x124) != 0) {
        RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 0xF, 0xA, (s8 *)(&B_002DDF40 + 0x4A8));
    }
}

}
