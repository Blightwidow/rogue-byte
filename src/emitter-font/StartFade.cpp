typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_StartFade {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
extern f32 g_2dded0;
struct FadeVtable { char pad[0x40]; s16 adjust; s16 pad2; void (*fn)(s8 *); };
struct FadeObj { char pad[0xC]; FadeVtable *vtable; char pad2[0x18]; u64 flags; char pad3[0x38]; f32 value; };
void StartFade(FadeObj *obj) {
    if ((int)(obj->flags >> 0x3C) & 1) return;
    obj->value = g_2dded0;
    obj->vtable->fn((s8 *)obj + obj->vtable->adjust);
}
}
