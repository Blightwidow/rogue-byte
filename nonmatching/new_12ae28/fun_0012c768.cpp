#include "sly2.h"
struct KEYS_12C768 { int pad0; int count; float *times; float *axes[3]; int pad18[2]; float defaults[3]; };
struct STATE_12C768 {
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
int func_0012C708(KEYS_12C768 *, float);
}
extern QW g_2a2dd0;
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW RotY(QW q) { QW t; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); return t; }
static inline QW RotZ(QW q) { QW t; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); return t; }
static inline QW RotY2(QW q, QW prev) { QW t; asm("prot3w %0, %1" : "=r" (t) : "r" (q), "0" (prev)); return t; }
static inline QW RotZ2(QW q, QW prev) { QW t; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q), "0" (prev)); return t; }
static inline float Mtc1(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
extern "C" void func_0012C768(KEYS_12C768 *keys, STATE_12C768 *state, int index) {
    int axis;
    int nearEnds = 0;
    int nearStart;
    int nearEnd = 0;
    if (keys->count != 0) {
        index = func_0012C708(keys, *state->currentPtr);
        state->prevTime = keys->times[index - 1];
        state->nextTime = keys->times[index];
    } else {
        state->currentPtr = &state->prevTime;
        state->nextTime = 1.0f;
        state->nextPtr = &state->nextTime;
        state->prevTime = 0;
    }
    float **axisPtr = keys->axes;
    int offset = index * 8;
    unsigned int step = 0;
    float *outA = state->vecA;
    float *outB = state->vecB;
    float *outC = state->vecC;
    float *outD = state->vecD;
    float *defaultPtr = keys->defaults;
    do {
        char *base = (char *)*axisPtr;
        char *previous = base + (offset - 8);
        if (base != 0) {
            char *current = base + offset;
            *outA = *(float *)previous;
            *(int *)outB = *(int *)(previous + 4);
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
        outC++;
        outB++;
        outA++;
        defaultPtr++;
        axisPtr++;
    } while (step < 3U);
    QW first = *(QW *)state->vecA;
    QW second = *(QW *)state->vecC;
    nearStart = 0;
    if (Near(LaneX(second), LaneX(first))) {
        QW ty = RotY(second);
        float oy = Mtc1(ty);
        if (Near(oy, Mtc1(RotY2(first, ty)))) {
            QW tz = RotZ(second);
            float oz = Mtc1(tz);
            nearStart = Near(oz, Mtc1(RotZ2(first, tz))) != 0;
        }
    }
    if (nearStart != 0) {
        QW vec = *(QW *)state->vecB;
        QW origin = g_2a2dd0;
        nearEnds = 0;
        if (Near(LaneX(origin), LaneX(vec))) {
            QW ty = RotY(origin);
            float oy = Mtc1(ty);
            if (Near(oy, Mtc1(RotY2(vec, ty)))) {
                QW tz = RotZ(origin);
                float oz = Mtc1(tz);
                nearEnds = Near(oz, Mtc1(RotZ2(vec, tz))) != 0;
            }
        }
        if (nearEnds != 0) {
            QW vec2 = *(QW *)state->vecD;
            QW origin2 = g_2a2dd0;
            nearEnd = 0;
            if (Near(LaneX(origin2), LaneX(vec2))) {
                QW ty = RotY(origin2);
                float oy = Mtc1(ty);
                if (Near(oy, Mtc1(RotY2(vec2, ty)))) {
                    QW tz = RotZ(origin2);
                    float oz = Mtc1(tz);
                    nearEnd = Near(oz, Mtc1(RotZ2(vec2, tz))) != 0;
                }
            }
        }
    }
    short flagValue = 1;
    if (nearEnd != 0) {
        flagValue = 2;
    }
    state->flag = flagValue;
}
