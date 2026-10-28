#include "sly2.h"
struct VEntry { short delta; short index; void (*fn)(void *, int); };
struct EPSEL {
    char pad0[0xC]; VEntry *vptr; char pad2[0x60]; int a70; int a74; int a78; char pad1[0x94]; int episode; int episodeNext;
    int pad3; int mode; int sub; float tmode;
};
extern char B_002E65E0;
extern float g_2ddf0c;
extern "C" void TryAutosave(char *, int);
extern "C" void SetEpselHint(EPSEL *, int);
extern "C" void SetTimerTimers__FP5TIMER6TIMERS(EPSEL *, int);
extern "C" void SetBlotBlots(EPSEL *, int);
extern "C" int LabelFromEpselMode(EPSEL *);
extern "C" void SetEpselMode(EPSEL *pepsel, int mode, int sub)
{
    int modeOld = pepsel->mode;
    if (modeOld == mode && pepsel->sub == sub)
        return;
    switch (modeOld) {
    case 0:
        TryAutosave(&B_002E65E0, 1);
        break;
    case 4:
    case 6: {
        int episodeNext = pepsel->episodeNext;
        pepsel->episodeNext = -1;
        pepsel->episode = episodeNext;
        break;
    }
    case 2:
        SetEpselHint(pepsel, 0);
        break;
    }
    if (mode == 2) {
        SetEpselHint(pepsel, -1);
        SetEpselHint(pepsel, 0);
    }
    pepsel->a74 = -1;
    pepsel->a70 = -1;
    pepsel->a78 = -1;
    SetTimerTimers__FP5TIMER6TIMERS(pepsel, 1);
    SetBlotBlots(pepsel, 1);
    pepsel->sub = sub;
    pepsel->mode = mode;
    pepsel->tmode = g_2ddf0c;
    int label = LabelFromEpselMode(pepsel);
    if (label != -1) {
        VEntry *entry = &pepsel->vptr[49];
        entry->fn((char *)pepsel + entry->delta, label);
    }
}
