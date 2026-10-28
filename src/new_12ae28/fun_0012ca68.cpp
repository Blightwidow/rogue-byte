#include "sly2.h"
struct Acr { int pad0; int ckey; float *at; float *apg[3]; float pad[2]; VECTOR def; };
extern "C" {
int func_0012C708(Acr *acr, float t);
void EvaluateBezierFloat(float a, float b, float c, float d, float e, float f, float g, float *pos, float *vel);
}
void func_0012CA68(Acr *acr, VECTOR *pos, VECTOR *vel, float t, float svt)
{
    if (pos)
        *pos = acr->def;
    if (vel) {
        vel->z = 0.0f;
        vel->y = 0.0f;
        vel->x = 0.0f;
    }
    if (acr->ckey == 0)
        return;
    int ikey = func_0012C708(acr, t);
    int o = ikey * 8;
    int o1 = o - 8;
    float **pp = acr->apg;
    register int off asm("$19") = 0;
    do {
        float *apg = *pp;
        if (apg) {
            float *prev = (float *)((char *)apg + o1);
            float *key = (float *)((char *)apg + o);
            float tPrev = acr->at[ikey - 1];
            EvaluateBezierFloat(acr->at[ikey] - tPrev, t - tPrev, svt, prev[0], prev[1], key[0], key[1],
                pos ? (float *)((char *)pos + off) : 0, vel ? (float *)((char *)vel + off) : 0);
        }
        pp++;
        off += 4;
    } while (pp < &acr->apg[3]);
}
