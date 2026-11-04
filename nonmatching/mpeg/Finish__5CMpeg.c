#include "m2c_macros.h"

M2C_UNK Close__10CMpegAudio(s32);                   /* extern */
M2C_UNK Reset__10CMpegAudio(s32);                   /* extern */
M2C_UNK func_0024B530(void *);                      /* extern */
M2C_UNK func_0024B590(void *);                      /* extern */
extern s32 g_2dedbc;

void Finish__5CMpeg(void *arg0) {
    s32 temp_s0;
    void *temp_s1;

    temp_s0 = arg0 + 0x180;
    M2C_FIELD(arg0, s32 *, 0x114) = 0;
    temp_s1 = arg0 + 0x118;
    M2C_FIELD(arg0, s32 *, 0x10C) = 0;
    Reset__10CMpegAudio(temp_s0);
    Close__10CMpegAudio(temp_s0);
    func_0024B590(temp_s1);
    func_0024B530(temp_s1);
    if (M2C_FIELD(arg0, s32 *, 0x240) != 0) {
        do {

        } while (M2C_FIELD(arg0, s32 *, 0x240) != 0);
    }
    g_2dedbc = 3;
}
