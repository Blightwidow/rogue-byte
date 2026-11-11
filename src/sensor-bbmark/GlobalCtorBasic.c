#include "types.h"

void StaticInitBasic(s32, s32);

void GlobalCtorBasic(void) {
    StaticInitBasic(1, 0xFFFF);
}
