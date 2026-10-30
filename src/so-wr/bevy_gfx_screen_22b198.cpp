#include "sly2.h"
struct WIPE { int wipes; char pad[0x54 - 4]; void *pblot; };
extern "C" int FBlotLabelPlaying(void *, int);
extern "C" void SetWipeWipes(WIPE *, int);

void bevy_gfx_screen_22b198(WIPE *pwipe)
{
    int wipes = pwipe->wipes;
    switch (wipes) {
    case 1:
        if (FBlotLabelPlaying(pwipe->pblot, 0x314) == 0)
            wipes = 3;
        break;
    case 2:
        if (FBlotLabelPlaying(pwipe->pblot, 0x314) == 0)
            wipes = 0;
        break;
    default:
        break;
    case 0:
        break;
    }
    SetWipeWipes(pwipe, wipes);
}
