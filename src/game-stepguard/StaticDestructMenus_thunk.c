#include "types.h"

void StaticInitMenus(s32, s32);

void StaticDestructMenus_thunk(void) {
    StaticInitMenus(0, 0xFFFF);
}
