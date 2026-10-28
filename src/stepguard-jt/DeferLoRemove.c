#include "m2c_macros.h"

M2C_UNK **func_001A5D58();                          /* extern */
extern M2C_UNK func_001A5D08;

void DeferLoRemove(void) {
    *func_001A5D58() = &func_001A5D08;
}
