typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateAloXfWorldHierarchy {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK UpdateAloXfWorld();                         /* extern */
struct Vt { char pad0[0x90]; short offset; short pad; void (*method)(s8 *); };
struct Obj { char pad0[0xC]; Vt *vtable; char pad1[0x24 - 0x10]; Obj *next; };
void UpdateAloXfWorldHierarchy(s8 *arg0) {
    UpdateAloXfWorld();
    for (Obj *node = M2C_FIELD(arg0, Obj **, 0x64); node != M2C_FIELD(arg0, Obj **, 0x70); node = node->next) {
        node->vtable->method((s8 *)node + node->vtable->offset);
    }
}
}
