typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct Obj;
struct Vtbl { char pad[0x260]; s16 adjust; s16 pad2; void (*handler)(s8 *, s32); };
struct Obj { char pad0[0xC]; Vtbl *vtbl; char pad1[0x140]; s32 state; };
struct Msg { char pad[4]; Obj *obj; };
struct Obj2;
extern "C" {
void HandleLoMessage(s32, s32, Obj *);
void HandleGadgetObjMessage(s32 arg0, s32 arg1, Obj *arg2) {
    HandleLoMessage(arg0, arg1, arg2);
    if (arg1 == 4) {
        Obj *obj = arg2;
        arg2 = ((Msg *)arg2)->obj;
        if ((s32)obj == arg0 && (u32)(obj->state - 1) < 2U) {
            obj->vtbl->handler((s8 *)obj + obj->vtbl->adjust, 3);
        }
    }
}
}
