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

void SetMurrayCarryState(MURRAY *m, int carrys)
{
    int old = F(int, m, 0x1458);
    if (carrys == old)
        return;
    if (old == 0) {
        SetXfKind(m, m->xf1, 2);
        SetXfKind(m, m->xf2, 2);
    } else if (old >= 0) {
        if (old < 3) {
            void *pah = F(void *, m, 0x1030);
            void *paseg = F(void *, pah, 0x14);
            F(float, m, 0x1A0) = F(float, pah, 0x1C) / F(float, paseg, 0x74);
        }
    }
    F(int, m, 0x1458) = carrys;
    void *paseg = 0;
    void *psm = 0;
    int grfapl = 1;
    float tStart = 0.0f;
    F(float, m, 0x145C) = g_2dded0.time;
    switch (carrys) {
    case 0:
        SetXfKind(m, m->xf1, 1);
        SetXfKind(m, m->xf2, 1);
        psm = F(void *, m, 0x1510);
        m->goalVelocity = g_2a2dd0;
        break;
    case 1:
        paseg = F(void *, m, 0x1464);
        tStart = F(float, m, 0x1A0) * F(float, paseg, 0x74);
        ResetRunBlendFootsteps((char *)m + 0x1320);
        grfapl = 9;
        break;
    case 2:
        paseg = F(void *, m, 0x151C);
        grfapl = 9;
        tStart = F(float, m, 0x1A0) * F(float, paseg, 0x74);
        break;
    }
    RetractAsegaHandle((char *)m + 0x1030);
    RetractSmaRef((char *)m + 0x1034);
    ApplyAsegToHandle(tStart, 1.0f, paseg, m, grfapl, (char *)m + 0x1030);
    func_001F1448(psm, m, -1, grfapl, (char *)m + 0x1034);
}
