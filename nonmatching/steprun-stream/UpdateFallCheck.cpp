#include "sly2.h"
struct FCVT { char pad[0x260]; short delta; char pad2[0x264 - 0x262]; int (*fn)(void *, int); };
struct FCSUB { char pad[0xC]; FCVT *vt; };
struct FCOBJ { FCSUB *psub; int state; float f8; char pad[0xC - 0xC]; void *pguard; };
extern "C" {
int FGuardOffGround(FCOBJ *);
void SetFallCheckState(FCOBJ *, int);
extern float g_2dded0;
extern float D_FLT_002C3DF0;
}

extern "C" void UpdateFallCheck(FCOBJ *pobj)
{
    if (pobj->pguard == 0) {
        return;
    }
    int guard = FGuardOffGround(pobj);
    int state = pobj->state;
    for (;;) {
        if (state != 1) {
            if (state < 2) {
                if (state == 0 && guard != 0) {
                    SetFallCheckState(pobj, 1);
                }
            } else if (state == 2) {
                if (guard == 0) {
                    SetFallCheckState(pobj, 0);
                }
            }
        } else {
            if (guard == 0) {
                SetFallCheckState(pobj, 0);
            } else if (D_FLT_002C3DF0 < g_2dded0 - pobj->f8) {
                FCSUB *psub = pobj->psub;
                FCVT *pvt = psub->vt;
                if (pvt->fn((char *)psub + pvt->delta, 0x4000) == 0) {
                    SetFallCheckState(pobj, 2);
                }
            }
        }
        int current = pobj->state;
        if (current == state) {
            break;
        }
        state = current;
    }
}
