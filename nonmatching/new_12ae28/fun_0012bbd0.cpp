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
/* lane 0 of a QW to an FP register (mtc1) */
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* lane 1 of a QW: prot3w rotates it down, then mtc1 */
static inline float Lane1(QW q) { float f; QW t; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
/* lane 2 of a QW: pextuw with zero brings it down, then mtc1 */
static inline float Lane2(QW q) { float f; QW t; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
static inline int Near3(QW p, QW q)
{
    return FFloatsNear__Ffff(Lane0(p), Lane0(q), 0.0001f) && FFloatsNear__Ffff(Lane1(p), Lane1(q), 0.0001f) &&
           FFloatsNear__Ffff(Lane2(p), Lane2(q), 0.0001f);
}
extern "C" void func_0012BBD0(KEYS_12BBD0 *keys, STATE_12BBD0 *state)
{
    int index = func_0012BB70(*state->pcur);
    state->t0 = *(float *)(keys->entries + (index * 0x20) - 0x14);
    state->a = *(V3_12BBD0 *)(keys->entries + (index * 0x20) - 0x20);
    state->q0 = *(QW *)(keys->entries + (index * 0x20) - 0x10);
    state->t1 = *(float *)(keys->entries + (index * 0x20) + 0xC);
    state->b = *(V3_12BBD0 *)(keys->entries + (index * 0x20));
    state->q1 = *(QW *)(keys->entries + (index * 0x20) + 0x10);
    int ok = 0;
    int same = Near3(*(QW *)&state->a, *(QW *)&state->b);
    if (same) {
        int second = Near3(g_2a2dd0, state->q0);
        if (second) {
            second = Near3(g_2a2dd0, state->q1);
            ok = second;
        }
    }
    state->flag = ok ? 2 : 1;
}
