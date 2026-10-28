// 0x22B050 InitWipe
#include "sly2.h"

struct WIPE {
    char pad[0x20];
};

extern "C" void SetWipeWipes(void* pwipe, int state);

void* InitWipe(void* pwipe)
{
    *(int*)((char*)pwipe + 0x54) = 0;
    *(int*)((char*)pwipe + 0x0) = -1;
    *(int*)((char*)pwipe + 0x58) = -1;
    SetWipeWipes(pwipe, 0);
    return pwipe;
}