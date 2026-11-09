#include "types.h"

struct JOY_1871C0 {
    char pad0[0x1000];
    s32 port;      // 0x1000
    s32 slot;      // 0x1004
    s32 pad1008;
    s32 joys;      // 0x100C
    s32 joyk;      // 0x1010
    f32 tJoys;     // 0x1014
    char pad1018[0x10CC - 0x1018];
    char rumble[0x10E8 - 0x10CC]; // 0x10CC
    s32 fRumble;   // 0x10E8
};

extern "C" {
extern f32 g_2ddf0c;
s32 FReadJoy__FP3JOY(JOY_1871C0 *);
void SetJoyJoys__FP3JOY4JOYS4JOYK(JOY_1871C0 *, s32, s32);
void UpdateRumble__FP6RUMBLE(void *);
u8 func_00243388(s32, s32);
void *memset(void *, int, unsigned int);
s32 scePadEnterPressMode(s32, s32);
s32 scePadGetState(s32, s32);
s32 scePadInfoAct(s32, s32, s32, s32);
s32 scePadInfoMode(s32, s32, s32, s32);
s32 scePadInfoPressMode(s32, s32);
s32 scePadSetActAlign(s32, s32, u8 *);
s32 scePadSetMainMode(s32, s32, s32, s32);

void UpdateJoy__FP3JOY(JOY_1871C0 *self) {
    u8 buf[16];
    if (self->joys == 0) {
        return;
    }
    s32 ready = 0;
    s32 r = func_00243388(self->port, self->slot);
    if (r == 6 || r == 2) {
        ready = 1;
    }
    s32 cur = self->joyk;
    if (self->joys != 3 && cur != 0 && 2.0f <= g_2ddf0c - self->tJoys) {
        r = 0;
    }
    if (cur != 0 && r == 0) {
        SetJoyJoys__FP3JOY4JOYS4JOYK(self, 1, 0);
    }
    if (!ready) {
        return;
    }
    s32 two = 2;
    s32 mode = self->joys;
    s32 n = self->joyk;
    switch (mode) {
    case 1:
        switch (n) {
        case 0: {
            s32 a = scePadInfoMode(self->port, self->slot, 1, 0);
            if (a != 0) {
                s32 b = scePadInfoMode(self->port, self->slot, 2, 0);
                if (b > 0) {
                    a = b;
                }
                if (a == 4 || a == 7) {
                    n = 1;
                    mode = 3;
                    if (b != 0) {
                        mode = n;
                    }
                }
            }
            break;
        }
        case 1:
            mode = (scePadSetMainMode(self->port, self->slot, 1, 3) == 1) ? two : n;
            break;
        case 2: {
            s32 count = scePadInfoAct(self->port, self->slot, -1, 0);
            if (count != n
                || scePadInfoAct(self->port, self->slot, 0, 1) != mode
                || scePadInfoAct(self->port, self->slot, 0, 2) != n
                || scePadInfoAct(self->port, self->slot, 0, 3) != 0
                || scePadInfoAct(self->port, self->slot, 1, 1) != mode
                || scePadInfoAct(self->port, self->slot, 1, 2) != mode
                || scePadInfoAct(self->port, self->slot, 1, 3) != mode) {
                mode = 3;
                break;
            }
            memset(buf, 0xFF, 6);
            for (s32 i = 0; i < count; i++) {
                buf[i] = i;
            }
            if (scePadSetActAlign(self->port, self->slot, buf) == 1) {
                mode = 2;
            }
            break;
        }
        case 3:
            if (scePadInfoPressMode(self->port, self->slot) != mode) {
                mode = 3;
                break;
            }
            if (scePadEnterPressMode(self->port, self->slot) == 1) {
                mode = two;
            }
            break;
        }
        break;
    case 2:
        switch (scePadGetState(self->port, self->slot)) {
        case 0:
            switch (self->joyk) {
            case 1:
                n = 2;
                mode = 1;
                break;
            case 2:
                n = 3;
                mode = 1;
                break;
            case 3:
                n = 4;
                mode = 3;
                break;
            default:
                n = 0;
                break;
            }
            break;
        case 1:
            mode = 1;
            break;
        case 2:
            break;
        default:
            n = 0;
            break;
        }
        break;
    case 3:
        if (FReadJoy__FP3JOY(self) != 0) {
            if (self->fRumble != 0 && self->joyk >= 3) {
                UpdateRumble__FP6RUMBLE(self->rumble);
            }
        } else {
            mode = 1;
            n = 0;
        }
        break;
    }
    SetJoyJoys__FP3JOY4JOYS4JOYK(self, mode, n);
}
}
