typedef signed char s8; typedef short s16; typedef int s32;

extern "C" {
void SetTag__4CRef4TAGK(s8 *, s32);
void FInvertMatrix4__FP7MATRIX4T0(s8 *, s8 *);
void CRef_CopyConstruct(s8 *, s8 *);
void CRef_Destruct(s8 *);

s8 *RefOpMatrixInvert(s8 *arg0, s32 unused_a1, s8 *arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));

    SetTag__4CRef4TAGK(sp, 0x1B);
    FInvertMatrix4__FP7MATRIX4T0(*(s8 **)(arg2 + 4), *(s8 **)(sp + 4));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}

}
