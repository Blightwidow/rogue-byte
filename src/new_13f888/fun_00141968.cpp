#include "sly2.h"

union VecQw { QW q; float f[4]; };

struct JtVtable { char pad[0x118]; short delta; short index; void (*fn)(void *, QW); };
struct JtSo { char pad[0x80]; QW accel; };
struct JtObject {
    char pad0[0xC]; JtVtable *vptr;
    char pad1[0xE8 - 0x10]; JtSo *pso;
    char pad2[0x248 - 0xEC]; float zOffset;
    char pad3[0x2C0 - 0x24C]; char jmp[0x2E8 - 0x2C0]; int unk2E8; int unk2EC;
    char pad4[0x2F4 - 0x2F0]; float duration;
    char pad5[0x300 - 0x2F8]; int state;
    char pad6[0x360 - 0x304]; VecQw velocity;
    char pad7[0xDF4 - 0x370]; int gadget;
};

extern "C" {
QW PosLoWorld(void *);
QW FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(QW, QW, float, QW);
void SetJmpState(void *, int, int, int);
}

extern "C" void func_00141968(float gravity, float duration, JtObject *pjt, QW target)
{
    struct { VecQw posFrom; VecQw vel; } local;
    local.posFrom.q = PosLoWorld(pjt);
    local.posFrom.f[2] = local.posFrom.f[2] + pjt->zOffset;
    local.vel.q = FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO(local.posFrom.q, target, gravity, pjt->pso->accel);
    JtVtable *vtable = pjt->vptr;
    vtable->fn((char *)pjt + vtable->delta, local.vel.q);
    if (pjt->gadget == -1) {
        SetJmpState(pjt->jmp, 8, 0, 0);
        pjt->state = 3;
        pjt->velocity.q = local.vel.q;
        pjt->velocity.f[2] = 0.0f;
        pjt->duration = duration;
        if (duration == pjt->velocity.f[2]) {
            pjt->unk2E8 = 0;
            pjt->unk2EC = 0;
        }
    }
}
