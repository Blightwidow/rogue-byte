typedef signed char s8; typedef short s16; typedef int s32;

extern "C" {
void StartAttach(s8 *, s32, s32, s32);

void SetJtAttach5(s8 *arg0, s32 arg1) {
    s8 *temp_v0;

    if (arg1 != 0) {
        StartAttach(arg0 + 0x4C0, 5, arg1, 0);
        return;
    }
    if (*(s32 *)(arg0 + 0x4C8) != 5) {
        return;
    }
    temp_v0 = *(s8 **)(arg0 + 0xC);
    (*(void (**)(s8 *, s32))(temp_v0 + 0x2C4))(arg0 + *(s16 *)(temp_v0 + 0x2C0), 0);
}

}
