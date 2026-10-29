typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
s32 GoalFollowCrv_FAtEnd(s8 *);
}
extern "C" {
void *PloFindSwObject_thunk(void *, int, int, int);
extern s8 B_003DD490[];
}
extern "C" void *func_001B1B98(s32 arg0, s32 arg1) {
    s8 *found;
    s8 *vtable;
    s32 offset;
    found = (s8 *)PloFindSwObject_thunk(B_003DD490, 1, arg1, arg0);
    if (found != 0) {
        vtable = M2C_FIELD(found, s8 **, 0xC);
        offset = M2C_FIELD(vtable, s16 *, 0x48);
        ((void (*)(s8 *))M2C_FIELD(vtable, void **, 0x4C))(found + offset);
    }
    return found;
}
