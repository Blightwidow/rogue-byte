#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
struct SO;
struct VT { char pad[0x300]; short delta; short idx; void (*fn)(void *, void *, float); };
struct VT2 { char pad[0x118]; short delta; short idx; void (*fn)(void *, QW); };
struct OBJ { char pad[0xC]; VT *vt; };
struct OBJ2 { char pad[0xC]; VT2 *vt; };
extern "C" {
void func_0012E460(void *);
void SetXfKind(void *, void *, int);
void RecalcSwOxfFilterForObject(void *, void *);
void DiscardSoXps(void *);
void GoalAnim_SetState(void *, int);
void func_0017AA78(void *, void *, QW *, QW *);
void *func_0012DE58(void *, void *, int, QW, QW, float);
void *PpoSwFocusBase(void *);
void TriggerJoyRumbleRumk__FP3JOY4RUMKf(void *, int, float);
float *PeaFindAsegLabel(void *, int);
void SeekAsega(void *, int, float, float);
QW PosLoWorld(char *);
QW ConvertXfPos(void *, void *, QW);
QW ConvertXfVec(void *, void *, QW);
}
void SetSoMass(SO *, float);
extern char B_003DD490[];
extern char B_002DFC00[];
extern float g_2be6fc;
extern float g_2be700;
extern float D_002BE704;
extern int D_002BE708;
extern float g_2dded0;
extern QW g_2a2dc0;
struct LOC {
    int fFound;      // 0x00
    char pad[0x2C];
    QW posAim;       // 0x30
    QW vecAim;       // 0x40
    QW s50;          // 0x50
    QW s60;          // 0x60
    QW s70;          // 0x70
};
void GoalAnimLeap_SetState(char *goal, int state)
{
    LOC l;
    int previous = *(int *)(goal + 0x50);
    if (state == previous)
        return;
    switch (previous) {
    case -1: {
        char *guard = *(char **)(goal + 0x10);
        SetSoMass((SO *)guard, g_2be6fc * *(float *)(*(char **)(guard + 0xE8) + 0xD0));
        break;
    }
    case 3:
        if (state != -1)
            SeekAsega(*(void **)(*(char **)(goal + 0x40) + 8), 0, 0.0f, 1.0f);
        break;
    }
    if ((unsigned)*(int *)(goal + 0x50) < 2) {
        if ((unsigned)state >= 2) {
            func_0012E460(goal + 0x64);
            char *guard = *(char **)(goal + 0x10);
            SetXfKind(guard, *(void **)(guard + 0x58), 2);
            guard = *(char **)(goal + 0x10);
            SetXfKind(guard, *(void **)(guard + 0x5C), 2);
        }
    }
    int now = *(int *)(goal + 0x50);
    int drivenBefore = 0;
    if ((unsigned)(now - 4) < 2 || now == 0)
        drivenBefore = 1;
    int drivenAfter = 0;
    if ((unsigned)(state - 4) < 2 || state == 0)
        drivenAfter = 1;
    *(int *)(goal + 0x50) = state;
    if (drivenBefore != drivenAfter) {
        void *pobj = *(void **)(goal + 0x10);
        RecalcSwOxfFilterForObject(B_003DD490, pobj);
        DiscardSoXps(*(void **)(goal + 0x10));
        *(int *)(goal + 0x50) = state;
    }
    *(float *)(goal + 0x54) = g_2dded0;
    switch (state) {
    case -1: {
        char *guard = *(char **)(goal + 0x10);
        float mass = *(float *)(*(char **)(guard + 0xE8) + 0xD0) / g_2be6fc;
        SetSoMass((SO *)guard, mass);
        GoalAnim_SetState(goal, 1);
        return;
    }
    case 0: {
        OBJ *target = *(OBJ **)(goal + 0x5C);
        target->vt->fn((char *)target + target->vt->delta, &l, g_2be700);
        func_0017AA78(goal, &l, &l.posAim, &l.vecAim);
        float inv = D_002BE704 / g_2be700;
        l.s70 = l.posAim;
        l.s50 = QuadFromFloat(inv);
        l.s60 = l.s50;
        QW pos = PosLoWorld(goal);
        OBJ2 *guard2 = *(OBJ2 **)(goal + 0x10);
        QW offset = VectorSub(l.s70, pos);
        QW aimed = VectorAdd(VectorScaleX(offset, l.s60), VectorScaleX(g_2a2dc0, VectorFromFloat(D_002BE704)));
        guard2->vt->fn((char *)guard2 + guard2->vt->delta, aimed);
        char *pxfLinear = *(char **)(*(char **)(goal + 0x10) + 0x58);
        if (*(void **)(goal + 0x64) == 0) {
            float tEnd = g_2dded0 + g_2be700;
            QW posLocal = ConvertXfPos(0, *(void **)(pxfLinear + 0xA0), l.posAim);
            QW vecLocal = ConvertXfVec(0, *(void **)(pxfLinear + 0xA0), l.vecAim);
            *(void **)(goal + 0x64) = func_0012DE58(*(void **)(goal + 0x10), pxfLinear, 0, posLocal, vecLocal, tEnd);
        }
        int held = 0;
        if (l.fFound)
            held = *(void **)(*(char **)(goal + 0x5C) + 0x10DC) == *(void **)(goal + 0x10);
        *(int *)(goal + 0x60) = held;
        if (*(int *)(*(char **)(goal + 0x10) + 0x334)) {
            void *focus = PpoSwFocusBase(B_003DD490);
            if (focus) {
                if (*(void **)(goal + 0x5C) == focus)
                    TriggerJoyRumbleRumk__FP3JOY4RUMKf(B_002DFC00, 3, 0.15f);
            }
        }
        return;

    }
    case 3: {
        float *label = PeaFindAsegLabel(*(void **)(*(char **)(goal + 0x40) + 4), 0x3C);
        if (label)
            SeekAsega(*(void **)(*(char **)(goal + 0x40) + 8), 0, *label, 1.0f);
        return;
    }
    case 4:
    case 5: {
        if (*(int *)(goal + 0x50) != 4)
            return;
        float *label = PeaFindAsegLabel(*(void **)(*(char **)(goal + 0x40) + 4), 0x173);
        if (label)
            SeekAsega(*(void **)(*(char **)(goal + 0x40) + 8), 0, *label, 1.0f);
        return;
    }
    }
}
