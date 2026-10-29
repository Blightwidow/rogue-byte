typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_OnAmbVoicePolled {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
struct Vt { char pad0[0x10]; short offset; short pad; void (*method)(s8 *); };
struct Amb { char pad0[0xC]; Vt *vtable; };
void SetAmbGrf(Amb *, s32, s32);
void StopAmb(Amb *, f32);
void OnAmbVoicePolled(s32 arg0, s64 arg1) {
    Amb *amb = (Amb *)(s32)arg1;
    if (arg0 == 0) {
        StopAmb(amb, 0.0f);
    } else {
        SetAmbGrf(amb, 0x400, 0x400);
    }
    amb->vtable->method((s8 *)amb + amb->vtable->offset);
}
}
