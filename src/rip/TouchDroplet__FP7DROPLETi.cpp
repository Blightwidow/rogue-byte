// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SOG_1D0D28 { char pad[0xB0]; };
struct SO_1D0D28 { char pad[0xE0]; int cgeom; SOG_1D0D28 *ageom; };
struct VT_1D0D28 { char pad[8]; short delta; short index; void (*fn)(char *, QW, float, int); };
struct RIPPLE_1D0D28 { char pad0[0x18]; float dtLifetime; int paloRender; float scale0; float scale1; char pad1[0xEC - 0x28]; VT_1D0D28 *vt; };
struct DROPLET_1D0D28 { char pad0[0x70]; QW pos; QW posPrev; char pad1[0xE0 - 0x90]; SO_1D0D28 *soTouch; char pad2[0xF4 - 0xE4]; int paloRipple; };
struct LSGHIT_1D0D28 { QW pos; char pad[0x50]; };
struct SWX_1D0D28 { char pad[1]; };
extern SWX_1D0D28 B_003DD490;
extern "C" int ClsgClipEdgeToObject(SOG_1D0D28 *, QW, QW, int, LSGHIT_1D0D28 *);
extern "C" RIPPLE_1D0D28 *PripNewRipg(SWX_1D0D28 *, int, int);
extern "C" void TouchRip__FP3RIPi(DROPLET_1D0D28 *, int);

extern "C" void TouchDroplet__FP7DROPLETi(DROPLET_1D0D28 *droplet, int touching)
{
    if (touching != 0 && droplet->paloRipple != 0) {
        LSGHIT_1D0D28 hit;
        hit.pos = droplet->pos;
        for (int index = 0; index < droplet->soTouch->cgeom; index++) {
            if (ClsgClipEdgeToObject(&droplet->soTouch->ageom[index], droplet->posPrev, droplet->pos, 1, &hit) != 0)
                goto found;
        }
    found:
        RIPPLE_1D0D28 *ripple = PripNewRipg(&B_003DD490, 7, 0);
        if (ripple != 0) {
            float scale = 40.0f;
            ripple->vt->fn((char *)ripple + ripple->vt->delta, hit.pos, scale, 0);
            ripple->dtLifetime = 0.75f;
            ripple->scale0 = scale;
            ripple->scale1 = 30.0f;
            ripple->paloRender = droplet->paloRipple;
        }
    }
    TouchRip__FP3RIPi(droplet, touching);
}
