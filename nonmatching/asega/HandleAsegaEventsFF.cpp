struct ASEGAEVENT131100 { float time; int kind; int pad[2]; };
struct ASEGADEF131100 { char pad[0xA0]; int cevent; ASEGAEVENT131100 *aevent; };
struct ASEGAVT131100 { char pad[8]; short delta; short index; void (*fn)(void *); short delta2; short index2; void (*fn2)(void *); };
struct ASEGA131100;
struct SCOPE131100 {
    ASEGA131100 *pasega;
    SCOPE131100(ASEGA131100 *pasega);
    ~SCOPE131100();
};
struct ASEGA131100 {
    char pad0[0xC];
    ASEGAVT131100 *vt;
    char pad1[4];
    ASEGADEF131100 *pdef;
    char pad2[4];
    float tPrev;
    float tCur;
    char pad3[0x1C];
    float dir;
    char pad4[0xC];
    int index;
};
inline SCOPE131100::SCOPE131100(ASEGA131100 *p) : pasega(p)
{
    p->vt->fn((char *)p + p->vt->delta);
}
inline SCOPE131100::~SCOPE131100()
{
    pasega->vt->fn2((char *)pasega + pasega->vt->delta2);
}
extern "C" {
int FAsegaGone(ASEGA131100 *);
void HandleAsegaEvent(ASEGA131100 *, ASEGAEVENT131100 *, int, ASEGADEF131100 *);
void HandleAsegaEventsFF(ASEGA131100 *self)
{
    if (self->pdef->cevent == 0)
        return;
    SCOPE131100 scope(self);
    self->tCur = self->tPrev;
    while (FAsegaGone(self) == 0) {
        ASEGADEF131100 *pdef = self->pdef;
        int index = self->index;
        float now = self->tCur;
        ASEGAEVENT131100 *event;
        if (index < pdef->cevent) {
            event = &pdef->aevent[index];
            if (event->time <= now && 0.0f <= self->dir) {
                self->index = index + 1;
                goto dispatch;
            }
        }
        if (index > 0) {
            if (now <= pdef->aevent[index - 1].time) {
                if (self->dir < 0.0f) {
                    int previous = index - 1;
                    self->index = previous;
                    event = &pdef->aevent[previous];
                    goto dispatch;
                }
            }
            self->tPrev = now;
            break;
        }
        self->tPrev = now;
        break;
    dispatch:
        switch (event->kind) {
        case 7:
        case 8:
        case 11:
        case 13:
        case 14:
        case 15:
        case 16:
        case 21:
        case 22:
        case 23:
        case 24:
            HandleAsegaEvent(self, event, index, pdef);
            break;
        }
    }
}
}
