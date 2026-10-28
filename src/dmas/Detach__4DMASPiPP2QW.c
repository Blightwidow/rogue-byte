#include "m2c_macros.h"

M2C_UNK Clear__4DMAS(void *);                       /* extern */
M2C_UNK EndDmaCnt__4DMAS();                         /* extern */
M2C_UNK func_001574A0(void *);                      /* extern */

void Detach__4DMASPiPP2QW(void *arg0, u32 *arg1, s32 *arg2) {
    EndDmaCnt__4DMAS();
    func_001574A0(arg0);
    if (arg1 != NULL) {
        *arg1 = (u32) (M2C_FIELD(arg0, s32 *, 0xC) - M2C_FIELD(arg0, s32 *, 4)) >> 4;
    }
    if (arg2 != NULL) {
        *arg2 = M2C_FIELD(arg0, s32 *, 4);
    }
    Clear__4DMAS(arg0);
}
