typedef signed char s8; typedef short s16; typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 FTaskRunning(s8 *);

void SendTaskTimeLimit(s8 *arg0, s32 arg1) {
    s32 timeLimitBlock[2];
    s8 *temp_v1;

    timeLimitBlock[0] = arg1;
    if (FTaskRunning(arg0) != 0) {
        timeLimitBlock[1] = (s32)timeLimitBlock;
        temp_v1 = *(s8 **)(arg0 + 0xC);
        (*(void (**)(s8 *, s32, s32, s32, s32 *, s32))(temp_v1 + 0x1C))(arg0 + *(s16 *)(temp_v1 + 0x18), 0x17, 0, 1, &timeLimitBlock[1], 0);
    }
}

}
