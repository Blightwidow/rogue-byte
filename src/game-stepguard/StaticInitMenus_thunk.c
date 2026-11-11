#include "types.h"

void StaticInitMenus(s32, s32);

void StaticInitMenus_thunk(void) {
    StaticInitMenus(1, 0xFFFF);
}
