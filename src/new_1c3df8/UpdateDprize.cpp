#include "vu0inline.h"
#include "sly2.h"
#include "ps2inline.h"
struct DPRIZEVT { char pad[0x260]; short delta; short index; void (*fn)(void *, int); };
struct DPRIZE {
    char pad0[0xC];
    DPRIZEVT *vt;
    char pad1[0x150 - 0x10];
    int state;
    float timeEnter;
    char pad2[0x180 - 0x158];
    VECTOR velocity;
    char pad3[0x1C4 - 0x190];
    int landing;
};
extern "C" {
void UpdateSo(DPRIZE *, float);
void func_001C6308(DPRIZE *);
void CheckDprizeBounce(DPRIZE *);
void CheckDprizeCollect(DPRIZE *);
extern float g_2dded0;
extern float D_002C0D50;
}
static inline void PostDprizeMessage(DPRIZE *dprize, int message)
{
    DPRIZEVT *vt = dprize->vt;
    vt->fn((char *)dprize + vt->delta, message);
}

void UpdateDprize(DPRIZE *dprize, float dt)
{
    UpdateSo(dprize, dt);
    func_001C6308(dprize);
    switch (dprize->state) {
    case 0:
        if (LaneX(SquaredLength(*(QW *)&dprize->velocity)) > 10000.0f)
            CheckDprizeBounce(dprize);
    case 5:
        CheckDprizeCollect(dprize);
        return;
    case 3:
        if (dprize->velocity.z < 0.0f)
            PostDprizeMessage(dprize, 4);
        return;
    case 4:
        if (dprize->landing != 0 && dprize->velocity.z < 25.0f) {
            dprize->landing = 0;
            PostDprizeMessage(dprize, 0);
        } else if (D_002C0D50 < g_2dded0 - dprize->timeEnter) {
            PostDprizeMessage(dprize, 2);
        } else {
            CheckDprizeBounce(dprize);
            CheckDprizeCollect(dprize);
        }
        return;
    case 1:
    case 2:
    case 6:
    default:
        return;
    }
}
