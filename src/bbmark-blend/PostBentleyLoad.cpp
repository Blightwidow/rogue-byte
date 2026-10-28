#include "sly2.h"
struct BENTLEY;
extern "C" void PostJtLoad(BENTLEY *);
extern "C" void *func_001F4C58(BENTLEY *, int, int);
extern "C" void BuildPlainBlend(BENTLEY *, void *, void *);
extern "C" void PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(void *);
extern "C" void InitLookRig(void *, BENTLEY *, QW, float, float);
extern "C" void InitJtLookRig(BENTLEY *, int);
extern "C" void SetBentleyState(BENTLEY *, int);
extern QW D_002BC920;
struct BENTLEY { char pad[0x10B8]; void *unk10B8; };
void PostBentleyLoad(BENTLEY *b)
{
    char *c = (char *)b;
    PostJtLoad(b);
    b->unk10B8 = func_001F4C58(b, 0xB, 1);
    BuildPlainBlend(b, c + 0x13E0, c + 0x14E0);
    BuildPlainBlend(b, c + 0x14F0, c + 0x15F0);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(c + 0x1320);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(c + 0x1600);
    InitLookRig(c + 0x1710, b, D_002BC920, -50.0f, 50.0f);
    InitJtLookRig(b, 0x16);
    SetBentleyState(b, 0);
}
