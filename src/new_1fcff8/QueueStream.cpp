// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad0[0x10]; short delta; short index; void (*release)(void *); char pad1[0x38 - 0x18]; short delta38; short index38; void (*wake)(void *); };
struct AMB { char pad[0xC]; VT *vt; };
struct RANGE {
    float minimum;
    float maximum;
    RANGE(float low, float high) { minimum = low; maximum = high; }
};

struct AMBREF;
extern "C" void func_00259B48(AMBREF *, AMB *);
extern "C" void func_00259BB0(AMBREF *, AMB *);

struct AMBREF {
    AMB *amb;
    ~AMBREF()
    {
        if (amb != 0) {
            VT *vt = amb->vt;
            vt->release((char *)amb + vt->delta);
        }
    }
    AMBREF(const AMBREF &other) { func_00259BB0(this, other.amb); }
    AMBREF &operator=(AMB *other)
    {
        func_00259B48(this, other);
        return *this;
    }
    AMBREF &operator=(const AMBREF &other)
    {
        func_00259B48(this, other.amb);
        return *this;
    }
};
struct SND { char pad[0x204]; int count; AMBREF q[8]; };

extern "C" {
extern int g_2dd5bc;
extern int g_2f7900;
extern int g_2e1e40;
AMBREF func_001FE478(SND *, int);
void StopAmb(AMB *, float);
int func_001FCFF8(SND *, int);
AMB *NewStreamAmb(int, int);
void AddAmbSlotSource(AMB *, unsigned, int, float, const RANGE *);

// `taken` is an AMBREF, a reference-holding smart pointer: its copy constructor and assignment call the real functions func_00259BB0 and
// func_00259B48 and its inline destructor releases through the vtable. That makes func_001FE478 return it through a hidden pointer (taken
// at sp+0, range at sp+0x10) and gives both release paths. It replaces the padding local the score-4 draft needed. AddAmbSlotSource is
// declared volume before range, as in CloneProxy (same registers either way; only this order reproduces retail's call-site scheduling).
AMB *QueueStream(SND *snd, int id)
{
    AMBREF taken = func_001FE478(snd, id);
    int count = snd->count;
    AMB *top = count > 0 ? *(AMB **)((char *)snd + count * 4 + 0x204) : 0;
    if (top != 0)
        StopAmb(top, 0.0f);
    if (taken.amb != 0) {
        VT *vt = taken.amb->vt;
        vt->wake((char *)taken.amb + vt->delta38);
    } else {
        int rec = func_001FCFF8(snd, id);
        if (rec == 0 || snd->count == 8)
            return 0;
        taken = NewStreamAmb(rec, 4);
        RANGE range(2000.0f, 5000.0f);
        AddAmbSlotSource(taken.amb, 3, g_2dd5bc, 1.0f, &range);
        AddAmbSlotSource(taken.amb, 3, g_2f7900, 1.0f, &range);
        AddAmbSlotSource(taken.amb, 4, g_2e1e40, 1.0f, &range);
    }
    return (snd->q[snd->count++] = taken).amb;
}
}
