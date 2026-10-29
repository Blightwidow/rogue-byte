typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C10C8 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

M2C_UNK HookupPzgraph(s32);                         /* extern */
s32 PloNew(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
s32 PvAllocSwClearImpl__Fi(s8 *, s32, s32);       /* extern */
M2C_UNK SetupDefaultPathzone(s32);                  /* extern */

void func_001C10C8(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x45CC) == 0) {
        temp_v0 = PloNew(0x11, 0, 0x2CA, -1);
        M2C_FIELD(arg0, s32 *, 0x45C8) = temp_v0;
        SetupDefaultPathzone(temp_v0);
        M2C_FIELD(arg0, s32 *, 0x45CC) = PvAllocSwClearImpl__Fi(sp, 0x30, 0x10);
    }
    HookupPzgraph(M2C_FIELD(arg0, s32 *, 0x45CC));
}

}
