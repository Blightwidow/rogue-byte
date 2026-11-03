#include "sly2.h"
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct Bentley {
    char pad0[0xC]; VT *vtable;
    char pad1[0x13D0 - 0x10]; int state;
};
struct VU_FLOAT {
    QW value;
    VU_FLOAT(float f) { asm("mfc1 %0, %1" : "=r" (value) : "f" (f)); }
};
static inline QW Scale(const VU_FLOAT &scale, QW vec)
{
    QW result;
    asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2\n\tvmulx.xyzw vf1, vf2, vf1x\n\tqmfc2.ni %0, vf1" : "=r" (result) : "m" (scale.value), "r" (vec));
    return result;
}
extern "C" {
void AddSoGravityAcceleration(void *);
void PresetStepAccel(void *);
void bevy_player_p18_gadget_glide_force(void *);
void PresetJtAccelHide__FP2JT(void *);
void PresetJtAccelZap(void *);
void PresetJtAccelPipe__FP2JT(void *);
void AddSoAcceleration(void *, QW);
extern float D_FLT_002BC990;
}
extern "C" void PresetBentleyAccel(Bentley *self, float dt)
{
    if (0xD == self->state)
        AddSoGravityAcceleration(self);
    else
        PresetStepAccel(self);
    char *base = (char *)self;
    switch (self->state) {
    case 2:
        bevy_player_p18_gadget_glide_force(base + 0x2C0);
        break;
    case 3:
        PresetJtAccelHide__FP2JT(base + 0x4C0);
        break;
    case 4:
        PresetJtAccelZap(base + 0xDF0);
        break;
    case 0xD:
        PresetJtAccelPipe__FP2JT(base + 0xF50);
        break;
    case 6:
        if (*(int *)(base + 0x16B0) == 2) {
            VT *vt = self->vtable;
            void *thisarg = base + vt->delta;
            QW (*fn)(void *) = vt->fn;
            VU_FLOAT scale(-D_FLT_002BC990);
            VU_FLOAT scaleCopy = scale;
            QW velocity = fn(thisarg);
            AddSoAcceleration(self, Scale(scale, velocity));
        }
        break;
    }
}
