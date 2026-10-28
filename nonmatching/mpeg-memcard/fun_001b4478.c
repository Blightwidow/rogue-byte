#include "m2c_macros.h"

M2C_UNK InitRenderNodeStack(void *);                /* extern */
M2C_UNK RenderGlobset(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK RenderGlobsetTree(void *, void *);          /* extern */

void func_001B4478(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC8) != 0) {
    char sp[0x400];
        InitRenderNodeStack(sp);
        RenderGlobsetTree(sp, arg0 + 0x80);
        return;
    }
    RenderGlobset(arg0 + 0x80, 0, 0, 0x3F800000, 0x3F800000);
}
