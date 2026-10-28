#include "sly2.h"
struct SCROLLER { char pad0[0x24]; short du; short dv; char pad28[0xC]; char sl[0x1C]; float speedU; float speedV; float modU; float modV; float masterU; float masterV; };
struct CLOCK { int unk0; float dt; };
extern "C" CLOCK g_2dded0;
extern "C" int FIsSlEmpty(void *);
extern "C" float fmodf(float, float);
extern "C" void SetSaiDuDv(SCROLLER *, float, float);

void UpdateScroller__FP8SCROLLERf(SCROLLER *pscroller)
{
    if (!FIsSlEmpty(&pscroller->sl)) {
        float du = fmodf((float)pscroller->du * 0.00024414062f + pscroller->speedU * pscroller->masterU * g_2dded0.dt, pscroller->modU);
        float dv = fmodf((float)pscroller->dv * 0.00024414062f + pscroller->speedV * pscroller->masterV * g_2dded0.dt, pscroller->modV);
        SetSaiDuDv(pscroller, du, dv);
    }
}
