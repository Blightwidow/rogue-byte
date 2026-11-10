#include "murray.h"
extern "C" void SetMurrayState(MURRAY *, int);
extern "C" void ReleaseMurrayObject(MURRAY *);

extern "C" void SetMurrayMode(MURRAY *murray, unsigned mode)
{
    switch (mode) {
    case 0:
        if (murray->ploCarried != 0)
            SetMurrayState(murray, 5);
        else
            SetMurrayState(murray, 0);
        break;
    case 1: {
        int state = murray->field_0x2C4;
        if (state < 0x11) {
            if (state >= 0xF)
                goto set2;
        }
        ReleaseMurrayObject(murray);
    set2:
        SetMurrayState(murray, 2);
        break;
    }
    case 2:
        SetMurrayState(murray, 0xD);
        break;
    case 3:
        ReleaseMurrayObject(murray);
        SetMurrayState(murray, 0xE);
        break;
    case 4:
        SetMurrayState(murray, 0x10);
        break;
    case 5:
        ReleaseMurrayObject(murray);
        SetMurrayState(murray, 0x11);
        break;
    case 6:
        ReleaseMurrayObject(murray);
        SetMurrayState(murray, 0x12);
        break;
    case 7:
        ReleaseMurrayObject(murray);
        SetMurrayState(murray, 0x13);
        break;
    case 8:
        ReleaseMurrayObject(murray);
        SetMurrayState(murray, 0x14);
        break;
    }
}
