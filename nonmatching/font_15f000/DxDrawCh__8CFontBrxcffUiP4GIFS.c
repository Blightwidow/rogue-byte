#include "m2c_macros.h"

M2C_UNK ListRGBAQ__4GIFSUif(s32, s32, M2C_UNK);     /* extern */
f32 ListUV__4GIFSii(s32, s32, s32);                 /* extern */
M2C_UNK ListXYZF__4GIFSiiii(s32, f32, f32, s32);    /* extern */
void *PglyffFromCh__8CFontBrxc(s32);                /* extern */

f32 DxDrawCh__8CFontBrxcffUiP4GIFS(void *arg0, s32 arg1, u32 arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    f32 temp_f0;
    f32 var_f0;
    f32 var_f1;
    s32 temp_s4;
    void *temp_v0;

    temp_v0 = PglyffFromCh__8CFontBrxc(arg1 & 0xFF);
    if (temp_v0 != NULL) {
        temp_s4 = 1 << ((s64) ((((u64) M2C_FIELD(arg0, u64 *, 0x50) >> 0x1E) & 0xF) << 0x20) >> 0x20);
        if (((fparg0 + ((f32) M2C_FIELD(temp_v0, u16 *, 6) * M2C_FIELD(arg0, f32 *, 0x10))) >= 0.0f) && (fparg0 <= 640.0f) && ((fparg1 + ((f32) M2C_FIELD(arg0, s32 *, 0xC) * M2C_FIELD(arg0, f32 *, 0x14))) >= 0.0f) && (fparg1 <= 492.80002f)) {
            ListRGBAQ__4GIFSUif(arg3, (arg2 & 0xFFFFFF) | ((((arg2 >> 0x18) + 1) & 0x1FE) << 0x17), 0);
            ListUV__4GIFSii(arg3, M2C_FIELD(temp_v0, u16 *, 2) * 0x10, (temp_s4 - M2C_FIELD(temp_v0, u16 *, 4)) * 0x10);
            ListXYZF__4GIFSiiii(arg3, M2C_ERROR(/* Read from unset register $f2 */), ((fparg0 * 0.8f) + 1792.0f) * 16.0f, M2C_FIELD(arg0, s32 *, 0x48));
            temp_f0 = ListUV__4GIFSii(arg3, (M2C_FIELD(temp_v0, u16 *, 2) + M2C_FIELD(temp_v0, u16 *, 6)) * 0x10, (temp_s4 - (M2C_FIELD(temp_v0, u16 *, 4) + M2C_FIELD(arg0, s32 *, 0xC))) * 0x10);
            ListXYZF__4GIFSiiii(arg3, temp_f0, temp_f0, M2C_FIELD(arg0, s32 *, 0x48));
        }
        var_f0 = (f32) (M2C_FIELD(temp_v0, u16 *, 6) + 1);
        var_f1 = M2C_FIELD(arg0, f32 *, 0x10);
    } else {
        var_f1 = (f32) M2C_FIELD(arg0, s32 *, 8);
        var_f0 = M2C_FIELD(arg0, f32 *, 0x10);
    }
    return var_f1 * var_f0;
}
