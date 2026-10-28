#include "sly2.h"
struct VTe { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct DP { char pad0[0xC]; VTe *vt; char pad1[0x150 - 0x10]; int state; char pad2[0x230 - 0x154]; void *task; };
extern "C" void *NewEmitter(int);
extern "C" void SetEmitterUnpositioned(void *, int);
extern "C" void RequestTaskState(void *, int, void *);
extern "C" void SetDprizeDprizes(DP *, int);

void func_001C6B28(DP *dp, int state)
{
    if (dp->state != state) {
        if (state == 1) {
            void *emitter = NewEmitter(0);
            SetEmitterUnpositioned(emitter, 0);
            if (dp->task)
                RequestTaskState(dp->task, 2, dp);
            state = 2;
            dp->vt->fn((char *)dp + dp->vt->delta, 5, 0, 0, 0, 0);
        }
        SetDprizeDprizes(dp, state);
    }
}
