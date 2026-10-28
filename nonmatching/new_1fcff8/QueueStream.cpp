#include "sly2.h"
struct VT { char pad0[0x10]; short delta; short index; void (*release)(void *); char pad1[0x38 - 0x18]; short delta38; short index38; void (*wake)(void *); };
struct AMB { char pad[0xC]; VT *vt; };
struct SND { char pad[0x204]; int count; AMB *q[8]; };

extern "C" {
extern int g_2dd5bc;
extern int g_2f7900;
extern int g_2e1e40;
void func_001FE478(AMB **, SND *, int);
void StopAmb(AMB *, float);
void func_00259B48(void *, void *);
int func_001FCFF8(SND *, int);
AMB *NewStreamAmb(int, int);
void AddAmbSlotSource(AMB *, unsigned, int, float *, float);

AMB *QueueStream(SND *snd, int id)
{
    struct { AMB *taken; int pad[3]; float range[2]; } l;
    func_001FE478(&l.taken, snd, id);
    int count = snd->count;
    AMB *top = count > 0 ? *(AMB **)((char *)snd + count * 4 + 0x204) : 0;
    if (top != 0)
        StopAmb(top, 0.0f);
    if (l.taken != 0) {
        VT *vt = l.taken->vt;
        vt->wake((char *)l.taken + vt->delta38);
    } else {
        int rec = func_001FCFF8(snd, id);
        if (rec == 0 || snd->count == 8) {
            if (l.taken != 0) {
                VT *vt = l.taken->vt;
                vt->release((char *)l.taken + vt->delta);
            }
            return 0;
        }
        func_00259B48(&l.taken, NewStreamAmb(rec, 4));
        float *prange = l.range;
        prange[0] = 2000.0f;
        prange[1] = 5000.0f;
        AddAmbSlotSource(l.taken, 3, g_2dd5bc, prange, 1.0f);
        AddAmbSlotSource(l.taken, 3, g_2f7900, prange, 1.0f);
        AddAmbSlotSource(l.taken, 4, g_2e1e40, prange, 1.0f);
    }
    int n = snd->count;
    AMB **slot = (AMB **)(n * 4 + (char *)snd + 0x208);
    asm("" : "+r" (slot));
    snd->count = n + 1;
    func_00259B48(slot, l.taken);
    AMB *result = *slot;
    if (l.taken != 0) {
        VT *vt = l.taken->vt;
        vt->release((char *)l.taken + vt->delta);
    }
    return result;
}
}
