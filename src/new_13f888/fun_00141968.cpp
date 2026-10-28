#include "sly2.h"
union V { QW q; float f[4]; };
struct VT { char pad[0x118]; short delta; short index; void (*fn)(void *, QW); };
struct SO { char pad[0x80]; QW accel; };
struct PXF { char pad[0xE8 - 0x0]; };
struct JT {
    char pad0[0xC]; VT *vptr; char pad1[0xE8 - 0x10]; SO *pso; char pad2[0x248 - 0xEC]; float zOffset;
    char pad3[0x2C0 - 0x24C]; char jmp[0x2E8 - 0x2C0]; int unk2E8; int unk2EC; char pad4[0x2F4 - 0x2F0]; float duration;
    char pad5[0x300 - 0x2F8]; int state; char pad6[0x360 - 0x304]; V velocity;
    char pad7[0xDF4 - 0x370]; int gadget;
};
extern "C" {
QW PosLoWorld(void *);
QW FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(QW, QW, float, QW, void *);
void SetJmpState(void *, int, int, int);
}
void func_00141968(float g, float dt, JT *pjt, QW target)
{
    register void *pcarry asm("$7");
    struct { V posFrom; V vel; } l;
    l.posFrom.q = PosLoWorld(pjt);
    l.posFrom.f[2] = l.posFrom.f[2] + pjt->zOffset;
    l.vel.q = FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(l.posFrom.q, target, g, pjt->pso->accel, pcarry);
    VT *vtable = pjt->vptr;
    vtable->fn((char *)pjt + vtable->delta, l.vel.q);
    if (pjt->gadget == -1) {
        SetJmpState(pjt->jmp, 8, 0, 0);
        pjt->state = 3;
        pjt->velocity.q = l.vel.q;
        pjt->velocity.f[2] = 0.0f;
        pjt->duration = dt;
        if (dt == pjt->velocity.f[2]) {
            pjt->unk2E8 = 0;
            pjt->unk2EC = 0;
        }
    }
}
