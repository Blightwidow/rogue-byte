#include "sly2.h"
struct AMB { char pad[0x40]; int f40; char pad2[0x0C]; unsigned short f50; unsigned short f52; char pad3[0x0C]; };
struct SND { char pad[0x204]; AMB *q[1]; };
struct VT { char pad0[0x10]; short delta; short index; void (*release)(void *); char pad1[0x38 - 0x18]; short delta38; short index38; void (*wake)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
extern "C" void func_001FE478(AMB **, SND *, int);
extern "C" void StopAmb(AMB *, float);
extern "C" void func_00259B48(AMB **, AMB *);

static inline int FAmbRequested(AMB *amb) { return amb->f52 != 0 || (amb->f50 & 1) != 0; }
static inline int FAmbIdle(AMB *amb) { return amb->f40 == 0 && !FAmbRequested(amb); }

void DequeueStream(SND *snd, int id)
{
    AMB *taken;
    func_001FE478(&taken, snd, id);
    if (taken != 0 && !FAmbIdle(taken)) {
        StopAmb(taken, 0.0f);
        int count = *(int *)&snd->q[0];
        AMB *top = count > 0 ? *(AMB **)(count * 4 + (char *)snd + 0x204) : 0;
        func_00259B48(&taken, top);
        if (taken != 0) {
            VT *vt = ((OBJ *)taken)->vt;
            vt->wake((char *)taken + vt->delta38);
        }
    }
    if (taken != 0) {
        VT *vt = ((OBJ *)taken)->vt;
        vt->release((char *)taken + vt->delta);
    }
}
