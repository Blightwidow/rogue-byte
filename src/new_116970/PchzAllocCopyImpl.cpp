typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void *PvAllocCopyImpl(void *, s32, const char *, s32);        /* extern */
u32 strlen(const char *);                                    /* extern */

char *PchzAllocCopyImpl(void *arg0, const char *arg1, s32 arg2) {
    return (char *)PvAllocCopyImpl(arg0, strlen(arg1) + 1, arg1, arg2);
}

}
