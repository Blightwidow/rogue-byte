typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 CMovieText_ClineWrap();                         /* extern */
f32 CMovieText_DxMaxLine(s8 *);                   /* extern */

void CMovieText_GetExtents(s8 *arg0, f32 *arg1, f32 *arg2) {
    f32 temp_f2;
    s32 temp_s1;

    temp_s1 = CMovieText_ClineWrap();
    temp_f2 = CMovieText_DxMaxLine(arg0);
    if (arg1 != NULL) {
        *arg1 = temp_f2;
    }
    if (arg2 != NULL) {
        *arg2 = (f32) temp_s1 * M2C_FIELD(arg0, f32 *, 0x84);
    }
}

}
