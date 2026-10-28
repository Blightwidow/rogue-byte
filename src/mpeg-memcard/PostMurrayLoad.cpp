#include "sly2.h"
struct STEP; struct BLRUN; struct ASEG;
struct MURRAY { char pad[0x18]; int oid; };
extern const QW RO_002A2DE0;
extern "C" void PostJtLoad();
extern "C" void PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(char *);
extern "C" void BuildPlainBlend(MURRAY *, char *, char *);
extern "C" void LoadJumpAnim(char *, MURRAY *);
extern "C" void CarryThrow_EnsureBlends(char *);
extern "C" void InitJtLookRig(MURRAY *, int);
extern "C" void *func_001F4C58(MURRAY *, int, int);
extern "C" int func_0012DC18(MURRAY *, void *, int, int, int, QW);
extern "C" void SetMurrayState(MURRAY *, int);

extern "C" void PostMurrayLoad(MURRAY *murray)
{
    char *base = (char *)murray;
    PostJtLoad();
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(base + 0x1320);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(base + 0x1460);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(base + 0x1630);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(base + 0x1540);
    BuildPlainBlend(murray, base + 0x16F0, base + 0x17F0);
    LoadJumpAnim(base + 0x1850, murray);
    CarryThrow_EnsureBlends(base + 0x1910);
    InitJtLookRig(murray, 0x16);
    void *sound = func_001F4C58(murray, murray->oid, 0xC);
    if (sound != 0)
        *(int *)(base + 0x1ACC) = func_0012DC18(murray, sound, 0, 7, 2, RO_002A2DE0);
    SetMurrayState(murray, 0);
}
