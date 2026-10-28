#include "m2c_macros.h"

s32 ClineWrap__9CRichTextf();                       /* extern */

f32 CRichText_DyWrap(void *arg0) {
    f32 temp_f20;
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    temp_f20 = (f32) M2C_FIELD(temp_v0, s32 *, 0xC) * M2C_FIELD(temp_v0, f32 *, 0x14);
    return temp_f20 * (f32) ClineWrap__9CRichTextf();
}
