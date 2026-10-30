typedef int s128 __attribute__((mode(TI)));
extern "C" {
struct MATRIX4_11C3D0 { s128 row[4]; };
void InvertMatrix4Affine(MATRIX4_11C3D0 *, int);
void __ml__FRC7MATRIX4T0(MATRIX4_11C3D0 *, int, MATRIX4_11C3D0 *);
void CalculateDmat4(int arg0, int arg1, MATRIX4_11C3D0 *out) {
    MATRIX4_11C3D0 product;
    MATRIX4_11C3D0 inverse;
    InvertMatrix4Affine(&inverse, arg0);
    __ml__FRC7MATRIX4T0(&product, arg1, &inverse);
    *out = product;
}
}
