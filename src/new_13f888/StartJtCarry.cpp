#include "sly2.h"
extern "C" {
void FadeAloIn(void *, float);
QW PosLoWorld(void *);
void CarryThrow_UpdateArc(void *, int);
void CarryThrow_SetState(void *, int);
}
struct SVT { char pad[0x2C0]; short delta; short idx; void (*fn)(void *, int); };
struct JtObj { char pad[0xC]; SVT *vt; char pad2[0x11B0 - 0x10]; char sub[0xE0]; QW pos; };
struct JtFull { char pad[0xC]; SVT *vt; char pad2[0x11B0 - 0x10]; char sub[0x10]; void *carried; char pad3[0x1290 - 0x11C4]; QW pos; };
void StartJtCarry(JtFull *jt, void *palo, void *ploFrom)
{
    FadeAloIn(palo, 0.25f);
    jt->carried = palo;
    jt->pos = PosLoWorld(ploFrom);
    CarryThrow_UpdateArc(jt->sub, 0);
    jt->vt->fn((char *)jt + jt->vt->delta, 7);
    CarryThrow_SetState(jt->sub, 7);
}
