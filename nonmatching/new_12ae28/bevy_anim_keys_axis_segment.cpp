#include "ps2inline.h"
struct KEYS_12C140 { int pad0; int count; float *times; float *axes[3]; int pad18[2]; float defaults[3]; };
struct STATE_12C140 {
    char pad0[0x80];
    float prevTime;
    float nextTime;
    float *currentPtr;
    float *nextPtr;
    char pad90[0xA];
    short flag;
    char pad9c[0x24];
    float vecA[4];
    float vecB[4];
    float vecC[4];
    float vecD[4];
};
extern "C" {
int FFloatsNear__Ffff(float, float, float);
int func_0012C0E0(KEYS_12C140 *, float);
}
extern QW g_2a2dd0;
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
extern "C" void bevy_anim_keys_axis_segment(KEYS_12C140 *keys, STATE_12C140 *state, int index) {
    int axis;
    if (keys->count != 0) {
        index = func_0012C0E0(keys, *state->currentPtr);
        state->prevTime = keys->times[index - 1];
        state->nextTime = keys->times[index];
    } else {
        state->currentPtr = &state->prevTime;
        state->nextTime = 1.0f;
        state->nextPtr = &state->nextTime;
        state->prevTime = 0;
    }
    float **axisPtr = keys->axes;
    int offset = index * 0xC;
    unsigned int step = 0;
    float *outB = state->vecB;
    float *outD = state->vecD;
    float *outC = state->vecC;
    float *outA = state->vecA;
    float *defaultPtr = keys->defaults;
    do {
        char *base = (char *)*axisPtr;
        char *previous = base + (offset - 0xC);
        if (base != 0) {
            char *current = base + offset;
            *outA = *(float *)previous;
            *(int *)outB = *(int *)(previous + 8);
            *outC = *(float *)current;
            *(int *)outD = *(int *)(current + 4);
        } else {
            *outA = *defaultPtr;
            *(int *)outD = 0;
            *outC = *defaultPtr;
            *(int *)outB = 0;
        }
        step++;
        outD++;
        outC++;
        outB++;
        outA++;
        axisPtr++;
        defaultPtr++;
    } while (step < 3U);
    QW first = *(QW *)state->vecA;
    QW second = *(QW *)state->vecC;
    int nearStart = 0;
    int nearEnd = 0;
    if (Near(LaneX(first), LaneX(second))) {
        if (Near(LaneYInGeneralRegister(first), LaneYInGeneralRegister(second))) {
            nearStart = Near(LaneZInGeneralRegister(first), LaneZInGeneralRegister(second)) != 0;
        }
    }
    if (nearStart != 0) {
        QW vec = *(QW *)state->vecB;
        QW origin = g_2a2dd0;
        int nearEnds = 0;
        if (Near(LaneX(origin), LaneX(vec))) {
            if (Near(LaneYInGeneralRegister(origin), LaneYInGeneralRegister(vec))) {
                nearEnds = Near(LaneZInGeneralRegister(origin), LaneZInGeneralRegister(vec)) != 0;
            }
        }
        if (nearEnds != 0) {
            QW vec2 = *(QW *)state->vecD;
            QW origin2 = g_2a2dd0;
            nearEnds = 0;
            if (Near(LaneX(origin2), LaneX(vec2))) {
                if (Near(LaneYInGeneralRegister(origin2), LaneYInGeneralRegister(vec2))) {
                    nearEnds = Near(LaneZInGeneralRegister(origin2), LaneZInGeneralRegister(vec2)) != 0;
                }
            }
            nearEnd = nearEnds;
        }
    }
    if (nearEnd != 0)
        state->flag = 2;
    else
        state->flag = 1;
}
