#include "m2c_macros.h"

M2C_UNK PauseMenu_Close(M2C_UNK *);                 /* extern */
extern M2C_UNK B_003D9ED0;

void PauseMenu_Close_thunk(void) {
    PauseMenu_Close(&B_003D9ED0);
}
