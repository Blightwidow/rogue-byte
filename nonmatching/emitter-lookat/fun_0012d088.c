#include "m2c_macros.h"

M2C_UNK func_0022C818(s32, void *, void *);         /* extern */
extern s128 g_2a2dd0;

void func_0012D088(void *arg0) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 8);
    M2C_FIELD(temp_a2, s128 *, 0xC0) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0xD0) = (s128) g_2a2dd0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), u16 *, 0x9A) = (u16) M2C_FIELD(arg0, u16 *, 0x1C);
    func_0022C818(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, void **, 8), temp_a2);
}
