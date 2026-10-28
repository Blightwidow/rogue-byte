#include "sly2.h"
struct VSLOT { short delta; short index; void (*fn)(void *); };
struct Jumper { char pad0[0xC]; VSLOT *vtable; char pad1[0x40 - 0x10]; QW dest; };
struct Murray {
    char pad0[0x190]; float v190[4];
    char pad1[0x1030 - 0x1A0];
    char a1030[4]; char a1034[0x1840 - 0x1034];
    int charges; float time; void *aseg0; void *aseg1;
    char a1850[0x1C]; float back; char a186c[0x1890 - 0x1870];
    char a1890[0x1900 - 0x1890];
    Jumper *jumper; void *aseg3; int flag;
};
extern "C" {
extern float g_2dded0;
extern QW g_2a2dd0;
void CancelJumper(Jumper *);
void StartJumpAnim(void *, Murray *, int, void *);
QW PosLoWorld(Murray *);
QW *PmatLoWorld(Murray *);
void RetractSmaRef(void *);
void ApplyAsegToHandle(float, float, void *, Murray *, int, void *);
}
void func_001B8D30(Murray *m, int charges)
{
    if (charges == m->charges)
        return;
    if (m->charges == 2) {
        CancelJumper(m->jumper);
        VSLOT *slot = &m->jumper->vtable[2];
        slot->fn((char *)m->jumper + slot->delta);
        m->jumper = 0;
        m->charges = charges;
    } else
        m->charges = charges;
    void *aseg = 0;
    int grfapl = 0;
    m->time = g_2dded0;
    switch (charges) {
    case 0:
        {
        aseg = m->aseg0;
        float *vec = m->v190;
        grfapl = 1;
        vec[2] = 0;
        vec[1] = 0;
        vec[0] = 0;
        }
        break;
    case 1:
        aseg = m->aseg1;
        grfapl = 9;
        break;
    case 2: {
        m->flag = 0;
        m->jumper = (Jumper *)m->a1890;
        StartJumpAnim(m->a1850, m, 1, m->a1890);
        Jumper *jumper = m->jumper;
        QW pos = PosLoWorld(m);
        QW negback[3];
        float nb = -m->back;
        QW bits;
        asm("mfc1 %0, %1" : "=r" (bits) : "f" (nb));
        negback[0] = bits; negback[1] = pos; negback[2] = bits;
        QW *row = PmatLoWorld(m);
        asm("lqc2 vf1, %0" : : "m" (row[0]));
        asm("lqc2 vf2, %0" : : "m" (negback[1]));
        QW *zero = &g_2a2dd0;
        asm("lqc2 vf3, %0" : : "m" (negback[2]));
        asm("vadda.xyzw ACC, vf0, vf2");
        asm("vmaddx.xyzw vf1, vf1, vf3x");
        asm("sqc2 vf1, %0" : "=m" (jumper->dest));
        *(QW *)m->v190 = *zero;
        break;
    }
    case 3:
        aseg = m->aseg3;
        grfapl = 1;
        break;
    case -1:
        m->flag = 0;
        return;
    }
    RetractSmaRef(m->a1034);
    ApplyAsegToHandle(0.0f, 1.0f, aseg, m, grfapl, m->a1030);
}
