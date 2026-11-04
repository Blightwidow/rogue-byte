#include "sly2.h"
struct BLOT { char pad0[0x58]; int stateBlot; };
struct HUDLABEL {
    char pad0[0x10];
    int state;
    float tState;
    int unk0x18;
    float tHold;
    int labelNext;
    int unk0x24;
    BLOT *pblot;
};
extern "C" {
void SetHudLabelState(HUDLABEL *, int);
int FDrawBlotMovie(BLOT *);
int FBlotLabelPlaying(BLOT *, int);
extern float g_2dded4;
}
void UpdateHudLabel(HUDLABEL *phudlabel)
{
    BLOT *pblot = phudlabel->pblot;
    if (pblot == 0)
        return;
    switch (phudlabel->state) {
    case 0:
    default:
        return;
    case 1:
        if (phudlabel->pblot->stateBlot != 2)
            return;
        SetHudLabelState(phudlabel, 2);
        return;
    case 2:
        if (phudlabel->labelNext != -1) {
            SetHudLabelState(phudlabel, 4);
            return;
        }
        if (phudlabel->tHold == 0.0f) {
            SetHudLabelState(phudlabel, 3);
            return;
        }
        if (phudlabel->tHold > 0.0f) {
            if (phudlabel->pblot == 0)
                return;
            if (FDrawBlotMovie(phudlabel->pblot) != 0)
                return;
            phudlabel->tState = phudlabel->tState + g_2dded4;
        }
        return;
    case 3:
        if (phudlabel->pblot->stateBlot >= 2)
            return;
        SetHudLabelState(phudlabel, 0);
        return;
    case 4:
        if (FBlotLabelPlaying(phudlabel->pblot, 0x312) != 0)
            return;
        if (phudlabel->labelNext == -1)
            SetHudLabelState(phudlabel, 0);
        else
            SetHudLabelState(phudlabel, 2);
        return;
    }
}
