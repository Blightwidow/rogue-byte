#include "types.h"
extern "C" {
typedef struct BLOTMOVIE {
    char pad0[0x44];
    s32 field_0x44;
    s32 field_0x48;
} BLOTMOVIE;

typedef struct BLOT {
    char pad0[0xC];
    s32 *field_0xC;
    char pad1[0x40];
    s32 field_0x50;
    s32 field_0x54;
    s32 field_0x58;
    f32 field_0x5C;
    char pad2[4];
    s32 field_0x64;
    f32 field_0x68;
    char pad3[0xC];
    s32 field_0x78;
    char pad4[4];
    s16 field_0x80;
    char pad5[2];
    s32 field_0x84;
    char pad6[0x20];
    s32 field_0xA8;
    char pad7[0x14];
    BLOTMOVIE *field_0xC0;
    char pad8[0x34];
    s32 field_0xF8;
    char field_0xFC[0x14];
    s32 field_0x110;
    s32 field_0x114;
    s32 field_0x118;
    s32 field_0x11C;
    s32 field_0x120;
} BLOT;

void SetBlotBlots(BLOT *, s32);
s32 SetTimerTimers__FP5TIMER6TIMERS(BLOT *, s32);

void Blot_Hide(BLOT *arg0) {
    SetTimerTimers__FP5TIMER6TIMERS(arg0, 1);
    if (arg0->field_0x78 == -1) {
        SetBlotBlots(arg0, 1);
    }
}

}
