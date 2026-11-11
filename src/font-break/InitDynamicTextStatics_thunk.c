#include "types.h"

s32 InitDynamicTextStatics(s32, s32);

void InitDynamicTextStatics_thunk(void) {
    InitDynamicTextStatics(1, 0xFFFF);
}
