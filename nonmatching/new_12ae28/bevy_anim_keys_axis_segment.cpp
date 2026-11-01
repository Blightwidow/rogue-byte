#include "sly2.h"
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
/* lane 0 of a QW to an FP register (mtc1) */
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* lane 1 of a QW: prot3w rotates it down (the compiler places it) */
static inline QW Rot3(QW q) { return __builtin_prot3w(q); }
/* lane 2 of a QW: pextuw with zero brings it down */
static inline QW Upper(QW q) { QW r; asm("pextuw %0, $0, %1" : "=r" (r) : "r" (q)); return r; }
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
static inline int Near3(QW p, QW q) { return Near(Lane0(p), Lane0(q)) && Near(Lane0(Rot3(p)), Lane0(Rot3(q))) && Near(Lane0(Upper(p)), Lane0(Upper(q))); }
extern "C" void bevy_anim_keys_axis_segment(KEYS_12C140 *keys, STATE_12C140 *state, int index) {
    int axis;
    int nearEnds = 0;
    int nearStart;
    int nearEnd = 0;
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
    float *outA = state->vecA;
    float *outB = state->vecB;
    float *outC = state->vecC;
    float *outD = state->vecD;
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
            *(int *)outB = 0;
            *outC = *defaultPtr;
            *(int *)outD = 0;
        }
        step++;
        outD++;
        outB++;
        outC++;
        outA++;
        defaultPtr++;
        axisPtr++;
    } while (step < 3U);
    QW first = *(QW *)state->vecA;
    QW second = *(QW *)state->vecC;
    nearStart = Near3(second, first);
    if (nearStart != 0) {
        QW vec = *(QW *)state->vecB;
        QW origin = g_2a2dd0;
        nearEnds = Near3(origin, vec);
        if (nearEnds != 0) {
            QW vec2 = *(QW *)state->vecD;
            QW origin2 = g_2a2dd0;
            nearEnd = Near3(origin2, vec2);
        }
    }
    short flagValue = 1;
    if (nearEnd != 0) {
        flagValue = 2;
    }
    state->flag = flagValue;
}
