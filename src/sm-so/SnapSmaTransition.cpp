typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK EndSmaTransition(s8 *);                   /* extern */
void RetractAsega(s8 *);                       /* extern */
M2C_UNK SeekAsega(s8 *, M2C_UNK, f32, f32);   /* extern */

void SnapSmaTransition(s8 *arg0) {
    f32 temp_f13;
    s8 *temp_s0;

    temp_s0 = M2C_FIELD(arg0, s8 **, 0x30);
    if (temp_s0 != NULL) {
        M2C_FIELD(arg0, s8 **, 0x30) = NULL;
        temp_f13 = M2C_FIELD(temp_s0, f32 *, 0x40);
        if (temp_f13 < 0.0f) {
            SeekAsega(temp_s0, 0, 0, temp_f13);
        } else {
            SeekAsega(temp_s0, 2, 0, temp_f13);
        }
        RetractAsega(temp_s0);
        EndSmaTransition(arg0);
    }
}

}
