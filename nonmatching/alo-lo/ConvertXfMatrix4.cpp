typedef int s32;
extern "C" {
struct M4_22FF40 { float f[16]; } __attribute__((aligned(16)));
void InvertMatrix4Affine(M4_22FF40 *, void *);
void __ml__FRC7MATRIX4T0(M4_22FF40 *, void *, void *);
s32 memcpy(s32, void *, s32);
s32 ConvertXfMatrix4(s32 arg0, char *arg1, char *arg2, M4_22FF40 *arg3) {
    M4_22FF40 result;
    M4_22FF40 tmp;
    M4_22FF40 inverse;
    void *source;
    if (arg1 != 0) {
        if (arg2 != 0) {
            InvertMatrix4Affine(&inverse, arg2 + 0x40);
            __ml__FRC7MATRIX4T0(&tmp, &inverse, arg1 + 0x40);
            source = &tmp;
        } else {
            source = arg1 + 0x40;
        }
        goto common;
    }
    if (arg2 != 0) {
        InvertMatrix4Affine(&tmp, arg2 + 0x40);
        source = &tmp;
common:
        __ml__FRC7MATRIX4T0(&result, source, arg3);
        memcpy(arg0, &result, 0x40);
    } else {
        memcpy(arg0, arg3, 0x40);
    }
    return arg0;
}
}
