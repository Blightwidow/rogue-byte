// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Anim { char pad[0x60]; float low; float high; char pad2[0x58]; struct Clip *clip; };
struct Clip { char pad[0xC]; int flags; };
struct Obj {
    char pad0[0xF00];
    Anim *playing;
    float timer;
};
extern "C" void StopAnimref(Clip *);
extern "C" void StartAnimref(Clip *, Obj *, int, float);
extern "C" float GRandInRange(float, float);
extern "C" void func_0020AC28(Obj *, Anim *, int, QW);
extern float g_2dded0;
extern "C" const float RO_FLT_002A88C4;
void func_0020AB68(Obj *self, Anim *anim, int mode, QW vec) {
    if (self->playing) {
        StopAnimref(self->playing->clip);
        Anim *old = self->playing;
        float base = g_2dded0;
        float wait = base + GRandInRange(old->low, old->high);
        self->playing = 0;
        self->timer = wait;
    }
    self->playing = anim;
    if (anim) {
        Clip *clip = anim->clip;
        StartAnimref(clip, self, clip->flags | 1, 0.0f);
        self->timer = RO_FLT_002A88C4;
    }
    func_0020AC28(self, anim, mode, vec);
}
