#include "sly2.h"
struct SWHITFX156B98 { char pad[0x4020]; void *player0; void *player1; };
extern "C" {
void PhitfxSpawn(void *, QW, int);
void SpawnSwHitFx(SWHITFX156B98 *sw, int kind, QW pos, int arg)
{
    void *target;
    switch (kind) {
    case 0:
        target = sw->player0;
        break;
    case 1:
        target = sw->player1;
        break;
    }
    PhitfxSpawn(target, pos, arg);
}
}
