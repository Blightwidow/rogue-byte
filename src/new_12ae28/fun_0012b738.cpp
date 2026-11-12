#include "sly2.h"
struct V3_12B738 { float x; float y; float z; };
struct KEY_12B738 { V3_12B738 a; float t; QW q0; V3_12B738 b; float u; QW q1; };
struct KEYS_12B738 { char pad[8]; char *entries; };
struct STATE_12B738 {
    char pad0[0x80]; float t0; float t1; float *pcur; char pad8c[0x9A - 0x8C]; short flag;
    char pad9c[0xC0 - 0x9C]; V3_12B738 a; float pada; QW q0; V3_12B738 b; float padb; QW q1;
};
extern "C" {
int IkeyFindAcrb(float);
int FFloatsNear__Ffff(float, float, float);
}
extern QW g_2a2dd0;
#include "ps2inline.h"
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
static inline int Near3(QW p, QW q)
{
    return Near(LaneX(p), LaneX(q)) && Near(LaneYInGeneralRegister(p), LaneYInGeneralRegister(q)) &&
           Near(LaneZInGeneralRegister(p), LaneZInGeneralRegister(q));
}
extern "C" void func_0012B738(KEYS_12B738 *keys, STATE_12B738 *state)
{
    int index = IkeyFindAcrb(*state->pcur);
    state->t0 = *(float *)(keys->entries + (index * 0x30) - 0x24);
    state->a = *(V3_12B738 *)(keys->entries + (index * 0x30) - 0x30);
    state->q0 = *(QW *)(keys->entries + (index * 0x30) - 0x10);
    state->t1 = *(float *)(keys->entries + (index * 0x30) + 0xC);
    state->b = *(V3_12B738 *)(keys->entries + (index * 0x30));
    state->q1 = *(QW *)(keys->entries + (index * 0x30) + 0x10);
    int ok = 0;
    int same = Near3(*(QW *)&state->a, *(QW *)&state->b);
    if (same) {
        int second = Near3(g_2a2dd0, state->q0);
        if (second) {
            ok = Near3(g_2a2dd0, state->q1);
        }
    }
    state->flag = ok ? 2 : 1;
}
