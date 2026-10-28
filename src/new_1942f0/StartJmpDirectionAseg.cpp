/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct XFR { char pad[0x40]; float x; float y; };
struct JOY { char pad[0x18]; float rad; };
struct JTX { char pad0[0x60]; XFR *xf; char pad1[0x150 - 0x64]; JOY *joy; char pad2[0x1030 - 0x154]; char *aseg; };
struct JMP {
    JTX *jt; int pad4; int idir; char pad0C[0x1C - 0xC]; int jtbs; char pad20[0x30 - 0x20]; int flag;
    char pad34[0x120 - 0x34]; void *table[5]; void *table2[1];
};
extern "C" {
float atan2f(float, float);
float RadNormalize__Ff(float);
void RetractSmaRef(void *, int);
void ApplyAsegToHandle(void *, void *, int, void *, float, float);
}
extern "C" void StartJmpDirectionAseg(JMP *jmp)
{
    jmp->flag = 1;
    float heading = atan2f(jmp->jt->xf->y, jmp->jt->xf->x);
    float delta = RadNormalize__Ff(jmp->jt->joy->rad - heading);
    float magnitude = delta < 0 ? -delta : delta;
    float limitLow = 1.0995574f;
    asm volatile("nop" : "+f" (limitLow));
    if (magnitude < limitLow) {
        jmp->idir = 3;
    } else {
        float limitHigh = 2.042035f;
        asm volatile("nop" : "+f" (limitHigh));
        if (limitHigh < magnitude) {
            jmp->idir = 4;
        } else {
            float zero = 0.0f;
            asm volatile("nop" : "+f" (zero));
            if (zero < delta)
                jmp->idir = 2;
            else
                jmp->idir = 1;
        }
    }
    char *current = jmp->jt->aseg;
    int jtbs = jmp->jtbs;
    void *aseg;
    if (jtbs == 2)
        aseg = jmp->table2[jmp->idir];
    else
        aseg = jmp->table[jmp->idir];
    if (aseg == 0) {
        if (jtbs == 2)
            aseg = jmp->table2[0];
        else
            aseg = jmp->table[0];
        if (aseg == 0)
            aseg = jmp->table[0];
    }
    RetractSmaRef((char *)jmp->jt + 0x1034, jtbs);
    JTX *jt2 = jmp->jt;
    ApplyAsegToHandle(aseg, jt2, 1, (char *)jt2 + 0x1030, *(float *)(current + 0x1C), *(float *)(current + 0x40));
}
