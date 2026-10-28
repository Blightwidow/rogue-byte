struct BLOTVT { char pad[0x190]; short delta; short index; void (*fn)(void *); };
struct BLOT { char pad[0xC]; BLOTVT *vt; };
struct HUDLABEL {
    char pad[0x10]; int state; float tState; int label; float tHold; int labelNext; float tHoldNext; BLOT *pblot;
};
extern "C" {
struct CLK { float t; float dt; };
extern CLK g_2dded0;
void PlayBlotLabel(BLOT *, int);
void SetBlotLabelList(BLOT *, int, int *);
void SetHudLabelState(HUDLABEL *phudlabel, int state)
{
    int statePrevious = phudlabel->state;
    if (state == statePrevious)
        return;
    switch (statePrevious) {
    case 3:
        if (state == 1 && phudlabel->tState == g_2dded0.t)
            state = 2;
        break;
    case 4:
        phudlabel->label = phudlabel->labelNext;
        phudlabel->tHold = phudlabel->tHoldNext;
        phudlabel->labelNext = -1;
        phudlabel->tHoldNext = -1.0f;
        break;
    }
    if (state == 0)
        phudlabel->label = -1;
    if (phudlabel->pblot != 0) {
        if (phudlabel->state == 4 && state == 2)
            PlayBlotLabel(phudlabel->pblot, 0x310);
        switch (state) {
        case 4:
            PlayBlotLabel(phudlabel->pblot, 0x312);
            break;
        case 3:
            phudlabel->pblot->vt->fn((char *)phudlabel->pblot + phudlabel->pblot->vt->delta);
            break;
        case 1:
            SetBlotLabelList(phudlabel->pblot, 1, &phudlabel->label);
            break;
        }
    }
    phudlabel->state = state;
    phudlabel->tState = g_2dded0.t;
}
}
