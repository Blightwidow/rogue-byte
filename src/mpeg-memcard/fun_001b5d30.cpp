#include "sly2.h"
struct MURRAY { char pad0[0x58]; int xf1; int xf2; char pad1[0x190 - 0x60]; QW goalVelocity; };
extern "C" {
void SetXfKind(void *, int, int);
void ResetRunBlendFootsteps(void *);
void RetractAsegaHandle(void *);
void RetractSmaRef(void *);
void ApplyAsegToHandle(float, float, void *, void *, int, void *);
void func_001F1448(void *, void *, int, int, void *);
extern QW g_2a2dd0;
}
struct Clock { float time; float dt; };
extern Clock g_2dded0;
#define F(type, base, off) (*(type *)((char *)(base) + (off)))

extern "C" void func_001B5D30(MURRAY *m, int focus)
{
    if (focus == F(int, m, 0x17F4))
        return;
    if (F(int, m, 0x17F4) == 0) {
        SetXfKind(m, m->xf1, 2);
        SetXfKind(m, m->xf2, 2);
    }
    F(int, m, 0x17F4) = focus;
    void *paseg = 0;
    void *psm = 0;
    int grfapl = 1;
    F(float, m, 0x17F8) = g_2dded0.time;
    switch (focus) {
    case 0:
        SetXfKind(m, m->xf1, 1);
        SetXfKind(m, m->xf2, 1);
        psm = F(void *, m, 0x16E0);
        m->goalVelocity = g_2a2dd0;
        break;
    case 2:
        paseg = F(void *, m, 0x17F0);
        grfapl = 9;
        break;
    case 1:
        paseg = F(void *, m, 0x1634);
        ResetRunBlendFootsteps((char *)m + 0x1630);
        grfapl = 9;
        break;
    }
    RetractAsegaHandle((char *)m + 0x1030);
    RetractSmaRef((char *)m + 0x1034);
    ApplyAsegToHandle(0.0f, 1.0f, paseg, m, grfapl, (char *)m + 0x1030);
    func_001F1448(psm, m, -1, grfapl, (char *)m + 0x1034);
}
