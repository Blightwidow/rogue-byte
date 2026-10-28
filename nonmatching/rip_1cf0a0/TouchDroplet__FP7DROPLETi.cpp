#include "sly2.h"
struct SOG { char pad[0xB0]; };
struct SO { char pad[0xE0]; int cgeom; SOG *ageom; };
struct VT { char pad[8]; short delta; short index; void (*fn)(char *, QW, float, int); };
struct RIPPLE { char pad0[0x18]; float dtLifetime; int paloRender; float scale0; float scale1; char pad1[0xEC - 0x28]; VT *vt; };
struct DROPLET { char pad0[0x70]; QW pos; QW posPrev; char pad1[0xE0 - 0x90]; SO *soTouch; char pad2[0xF4 - 0xE4]; int paloRipple; };
struct LSGHIT { QW pos; char pad[0x50]; };
struct SWX { char pad[1]; };
extern SWX B_003DD490;
extern "C" int ClsgClipEdgeToObject(SOG *, QW, QW, int, LSGHIT *);
extern "C" RIPPLE *PripNewRipg(SWX *, int, int);
extern "C" void TouchRip__FP3RIPi(DROPLET *, int);

void TouchDroplet(DROPLET *droplet, int touching)
{
    if (touching != 0 && droplet->paloRipple != 0) {
        LSGHIT hit;
        hit.pos = droplet->pos;
        SO *soTouch = droplet->soTouch;
        if (soTouch->cgeom > 0) {
            int offset = 0;
            int index = 0;
            do {
                if (ClsgClipEdgeToObject((SOG *)((char *)soTouch->ageom + offset), droplet->posPrev, droplet->pos, 1, &hit) != 0)
                    break;
                index++;
                soTouch = droplet->soTouch;
                offset += 0xB0;
            } while (index < soTouch->cgeom);
        }
        RIPPLE *ripple = PripNewRipg(&B_003DD490, 7, 0);
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
