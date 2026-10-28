#include "m2c_macros.h"

M2C_UNK Menu_SetDialog(void *, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_001D9870();                            /* extern */
extern f32 g_2ddf0c;

void Menu_Update(void *arg0) {
    func_001D9870();
    if (M2C_FIELD(arg0, f32 *, 0x34) <= g_2ddf0c) {
        Menu_SetDialog(arg0, -1, -1);
    }
}
