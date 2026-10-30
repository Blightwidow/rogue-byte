typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_DxDrawCh__8CFontBrxcffUiP4GIFS {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
void ListRGBAQ__4GIFSUif(s32, u32, f32);
void ListUV__4GIFSii(s32, s32, s32);
void ListXYZF__4GIFSiiii(s32, s32, s32, s32, s32);
s32 *PglyffFromCh__8CFontBrxc(s8 *, s32);
f32 DxDrawCh__8CFontBrxcffUiP4GIFS(s8 *arg0, s32 arg1, u32 arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    f32 temp_f26;
    f32 temp_f27;
    f32 var_f0;
    f32 var_f1;
    s32 temp_s4;
    s8 *temp_v0;
    temp_v0 = (s8 *)(PglyffFromCh__8CFontBrxc(arg0, arg1 & 0xFF));
    if (temp_v0 != NULL) {
        temp_s4 = 1 << ((s64) ((((u64) M2C_FIELD(arg0, u64 *, 0x50) >> 0x1E) & 0xF) << 0x20) >> 0x20);
        temp_f26 = fparg0 + ((f32) M2C_FIELD(temp_v0, u16 *, 6) * M2C_FIELD(arg0, f32 *, 0x10));
        temp_f27 = fparg1 + ((f32) M2C_FIELD(arg0, s32 *, 0xC) * M2C_FIELD(arg0, f32 *, 0x14));
        if ((temp_f26 >= 0.0f) && (fparg0 <= 640.0f) && (temp_f27 >= 0.0f) && (fparg1 <= 492.80002f)) {
            ListRGBAQ__4GIFSUif(arg3, (arg2 & 0xFFFFFF) | ((((arg2 >> 0x18) + 1) & 0x1FE) << 0x17), 0.0f);
            ListUV__4GIFSii(arg3, M2C_FIELD(temp_v0, u16 *, 2) * 0x10, (temp_s4 - M2C_FIELD(temp_v0, u16 *, 4)) * 0x10);
            ListXYZF__4GIFSiiii(arg3, (s32) (((fparg0 * 0.8f) + 1792.0f) * 16.0f), (s32) (((fparg1 * 0.45454547f) + 1936.0f) * 16.0f), M2C_FIELD(arg0, s32 *, 0x48), 0);
            ListUV__4GIFSii(arg3, (M2C_FIELD(temp_v0, u16 *, 2) + M2C_FIELD(temp_v0, u16 *, 6)) * 0x10, (temp_s4 - (M2C_FIELD(temp_v0, u16 *, 4) + M2C_FIELD(arg0, s32 *, 0xC))) * 0x10);
            ListXYZF__4GIFSiiii(arg3, (s32) (((temp_f26 * 0.8f) + 1792.0f) * 16.0f), (s32) (((temp_f27 * 0.45454547f) + 1936.0f) * 16.0f), M2C_FIELD(arg0, s32 *, 0x48), 0);
        }
        var_f0 = (f32) (M2C_FIELD(temp_v0, u16 *, 6) + 1);
        var_f1 = M2C_FIELD(arg0, f32 *, 0x10);
        return var_f0 * var_f1;
    } else {
        var_f1 = (f32) M2C_FIELD(arg0, s32 *, 8);
        var_f0 = M2C_FIELD(arg0, f32 *, 0x10);
        return var_f1 * var_f0;
    }
}
}
