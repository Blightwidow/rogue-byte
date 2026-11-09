#include "types.h"
struct Vjoy {
    char pad0[0x1C];
    float leftStick;
    char pad1[0xC];
    float rightStick;
    s32 buttonsNew;
    char pad2[0x44];
    s32 buttonsOld;
    char pad3[0xC];
    float buttonTimes[16];
    char leftTimes[8];
    char rightTimes[8];
};
extern "C" {
extern float g_2dded0;
}
extern "C" void UpdateVjoyPressTimes(Vjoy *vjoy)
{
    s32 buttonsOld = vjoy->buttonsOld;
    s32 buttonsNew = vjoy->buttonsNew;
    float timeNow = g_2dded0;
    s32 buttonsPressed = buttonsNew & ~buttonsOld;
    vjoy->buttonsOld = buttonsNew;
    if (buttonsPressed != 0) {
        float *pressTime = vjoy->buttonTimes;
        do {
            if (buttonsPressed & 1) {
                *pressTime = timeNow;
            }
            buttonsPressed >>= 1;
            pressTime++;
        } while (buttonsPressed != 0);
    }
    s32 leftIndex = 0;
    if (0.0f < vjoy->leftStick) {
        leftIndex = 4;
    }
    char *leftSlot = vjoy->leftTimes;
    *(float *)(leftSlot + leftIndex) = timeNow;
    s32 rightIndex = 0;
    if (0.0f < vjoy->rightStick) {
        rightIndex = 4;
    }
    char *rightSlot = vjoy->rightTimes;
    *(float *)(rightSlot + rightIndex) = timeNow;
}
