typedef int s32;
extern "C" s32 CploFindSwObjectsByClass(s32, s32, s32, s32, s32, void **);
extern "C" void SetGuardMode(void *, s32);
extern "C" void SetSwGuardsMode(s32 unusedWorld, s32 mode) {
    void *guards[0x20];
    s32 count = CploFindSwObjectsByClass(unusedWorld, 0x105, 0x38, 0, 0x20, guards);
    for (s32 index = 0; index < count; index++) {
        SetGuardMode(guards[index], mode);
    }
}
