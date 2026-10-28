#include "m2c_macros.h"

M2C_UNK RemoveDlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK func_001F3E00();                            /* extern */
extern M2C_UNK B_003E1444;
extern f32 g_2dded0;

void RemoveStepguardHierarchy(void *arg0) {
    func_001F3E00();
    RemoveDlEntry(&B_003E1444, arg0);
    M2C_FIELD(arg0, f32 *, 0xFF8) = (f32) g_2dded0;
}
