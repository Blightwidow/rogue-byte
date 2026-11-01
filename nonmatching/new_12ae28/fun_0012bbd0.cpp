#include "sly2.h"
struct V3_12BBD0 { float x; float y; float z; };
struct KEY_12BBD0 { V3_12BBD0 a; float t; QW q0; V3_12BBD0 b; float u; QW q1; };
struct KEYS_12BBD0 { char pad[8]; char *entries; };
struct STATE_12BBD0 {
    char pad0[0x80]; float t0; float t1; float *pcur; char pad8c[0x9A - 0x8C]; short flag;
    char pad9c[0xC0 - 0x9C]; V3_12BBD0 a; float pada; QW q0; V3_12BBD0 b; float padb; QW q1;
};
extern "C" {
int func_0012BB70(float);
int FFloatsNear__Ffff(float, float, float);
}
extern QW g_2a2dd0;
static inline int Near3(const float *p, const float *q)
{
    return FFloatsNear__Ffff(p[0], q[0], 0.0001f) && FFloatsNear__Ffff(p[1], q[1], 0.0001f) &&
           FFloatsNear__Ffff(p[2], q[2], 0.0001f);
}
extern "C" void func_0012BBD0(KEYS_12BBD0 *keys, STATE_12BBD0 *state)
{
    int index = func_0012BB70(*state->pcur);
    char *base = keys->entries + index * 0x20;
    state->t0 = *(float *)(base - 0x14);
    state->a = *(V3_12BBD0 *)(base - 0x20);
    state->q0 = *(QW *)(base - 0x10);
    state->t1 = *(float *)(base + 0xC);
    state->b = *(V3_12BBD0 *)base;
    state->q1 = *(QW *)(base + 0x10);
    int same = Near3(&state->a.x, &state->b.x);
    int second = 0;
    if (same) {
        second = Near3((float *)&g_2a2dd0, (float *)&state->q0);
        if (second)
            second = Near3((float *)&g_2a2dd0, (float *)&state->q1);
    }
    state->flag = second ? 2 : 1;
}
