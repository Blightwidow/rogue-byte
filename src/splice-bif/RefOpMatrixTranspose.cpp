typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
extern "C" {

void CRef_ConstructMatrix(void *ref, void *matrix);
void CRef_CopyConstruct(s32 dest, void *ref);
void CRef_Destruct(void *ref);
void TransposeMatrix4(void *dest, s32 src);

s32 RefOpMatrixTranspose(s32 arg0, s32 unused_a1, void *arg2) {
    char sp[0x50];
    char *matrix;

    matrix = sp + 0x10;
    TransposeMatrix4(matrix, *(s32 *)((char *)arg2 + 4));
    CRef_ConstructMatrix(sp, matrix);
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}

}
