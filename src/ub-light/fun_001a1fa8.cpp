typedef int s32; typedef long s64; typedef signed char s8;
extern "C" {
void SetJmpState(s32, s32, s32, s32);
void SetJtZapState(void *, s32);
void WarpZapToSafePoint();

void func_001A1FA8(s32 *arg0) {
    if (**(s32 **)((s8 *)arg0 + 0x10) > 0) {
        s8 *target = *(s8 **)((s8 *)arg0 + 0x30);
        if (target != 0 && (*(s64 *)(target + 0x148) & (0x8000L << 0x12))) {
            WarpZapToSafePoint();
        } else {
            SetJmpState(arg0[0] + 0x2C0, 0xB, 0, 0);
        }
        return;
    }
    SetJtZapState(arg0, 8);
}
}
