#include "sly2.h"
struct VJOY {
    char pad[0x1C];
    float sLeft;
    char pad2[0x2C - 0x20];
    float sRight;
    int grfbtn;
    char pad3[0x78 - 0x34];
    int grfbtnPrev;
    char pad4[0x88 - 0x7C];
    float atPress[16];
    float atStickLeft[2];
    float atStickRight[2];
};
extern float g_2dded0;
void UpdateVjoyPressTimes(VJOY *pvjoy)
{
    float tNow = g_2dded0;
    int grfbtnNew = pvjoy->grfbtn & ~pvjoy->grfbtnPrev;
    pvjoy->grfbtnPrev = pvjoy->grfbtn;
    if (grfbtnNew != 0) {
        float *ptPress = pvjoy->atPress;
        do {
            if ((grfbtnNew & 1) != 0)
                *ptPress = tNow;
            grfbtnNew >>= 1;
            ptPress++;
        } while (grfbtnNew != 0);
    }
    float left = pvjoy->sLeft;
    float zero;
    asm volatile("mtc1 $0, %0\n\tnop" : "=f" (zero) : "f" (left));
    pvjoy->atStickLeft[zero < left ? 1 : 0] = tNow;
    pvjoy->atStickRight[zero < pvjoy->sRight ? 1 : 0] = tNow;
}
