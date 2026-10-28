#include "sly2.h"
extern "C" void PrimeSlotheap(void *);
extern "C" void func_0020E338(void *);
extern "C" void func_0020E2B0(void *);
extern "C" void ClearSwRootFrameFlag(void *);
extern "C" void InitCloneSets(void *);
extern "C" void InitSwHudBlots(void *);
extern "C" void InitSwHitFxParms(void *);
extern "C" void func_001A3260(void *);
extern "C" void func_001C10C8(void *);
extern "C" void func_00210940(void *);
extern "C" void FindTargetIndicatorTemplate(void *);
extern "C" void ShutdownSplice__Fv(void *);
extern "C" void UpdateSwCallbacks(void *);
extern "C" void BuildPzgraphAdjacency(void *);
extern "C" void func_0014D470(void *);
extern "C" void bevy_camera_follow_activity(void *, int, int);
extern "C" char B_003D9E70[], B_002DDF40[], B_002DEB30[];
struct VT { char pad[0x78]; short delta; short index; void (*fn)(void *); };
struct OBJ { int a, b, c; VT *vt; };
void func_0020E740(char *sw)
{
    PrimeSlotheap(sw + 0x403C);
    PrimeSlotheap(sw + 0x4054);
    PrimeSlotheap(sw + 0x4070);
    PrimeSlotheap(sw + 0x4088);
    func_0020E338(sw);
    func_0020E2B0(sw);
    ClearSwRootFrameFlag(sw);
    InitCloneSets(sw);
    InitSwHudBlots(sw);
    InitSwHitFxParms(sw);
    func_001A3260(sw);
    func_001C10C8(sw);
    func_00210940(sw);
    FindTargetIndicatorTemplate(sw);
    ShutdownSplice__Fv(B_003D9E70);
    for (;;) {
        UpdateSwCallbacks(sw);
        OBJ **end = *(OBJ ***)(sw + 0x39E4);
        OBJ **begin = *(OBJ ***)(sw + 0x39E0);
        if (end == begin)
            break;
        OBJ **current = begin;
        if (current < end) {
            do {
                OBJ *object = *current++;
                object->vt->fn((char *)object + object->vt->delta);
            } while (current < *(OBJ ***)(sw + 0x39E4));
        }
        *(int *)(sw + 0x39E4) = *(int *)(sw + 0x39E0);
    }
    *(int *)(sw + 0x39E4) = 0;
    *(int *)(sw + 0x39E0) = 0;
    *(int *)(sw + 0x39D8) = 0;
    *(int *)(sw + 0x39D0) = 0;
    BuildPzgraphAdjacency(*(void **)(sw + 0x45CC));
    func_0014D470(B_002DDF40);
    bevy_camera_follow_activity(B_002DEB30, 4, 0);
}
