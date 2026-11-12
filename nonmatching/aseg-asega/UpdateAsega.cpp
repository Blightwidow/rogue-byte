/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct Aseg { char pad0[0x40]; unsigned grf; char pad44[0xA0 - 0x44]; int count; };
struct Asega;
struct Listener {
    virtual void Slot0();
    virtual void Notify(void *arg, void *arg2, float time, float rate);
};
struct Hook { Listener *listener; void *arg; char pad8[8]; Hook *next; };
struct AsegaBase {
    char pad[0xC];
    virtual void AddRef();
    virtual void Release();
    virtual void Slot3();
    virtual void Message(int msgid, void *arg);
};
struct Asega : AsegaBase {
    char pad10[4]; Aseg *aseg; char pad18[4]; float tLocal; char pad20[0x38 - 0x20];
    Hook *hooks; unsigned grf; float svt; char pad44[0x50 - 0x44]; int iea;
};
extern float g_2ddf10;
extern float g_2dded4;
extern "C" {
void HandleAsegaEvents(Asega *);
int FAsegaGone(Asega *);
int FWrapAsegaTime(Asega *, float *, float *);
void RetractAsega(Asega *);
}
static inline unsigned GrfValue(Aseg *aseg)
{
    unsigned value = aseg->grf;
    if ((value ^ 1) & 1)
        value = *(unsigned *)value;
    return value;
}
struct AsegaHold {
    Asega *asega;
    AsegaHold(Asega *target) { asega = target; asega->AddRef(); }
    ~AsegaHold() { asega->Release(); }
};
extern "C" void UpdateAsega(Asega *asega)
{
    if (__builtin_fabsf(asega->svt) < 0.0001f)
        return;
    AsegaHold hold(asega);
    unsigned grf = GrfValue(asega->aseg);
    float svtNow;
    float dtNow;
    if (grf & 0x100) {
        svtNow = asega->svt;
        dtNow = g_2ddf10;
    } else {
        svtNow = asega->svt;
        dtNow = g_2dded4;
    }
    asega->tLocal = asega->tLocal + svtNow * dtNow;
    HandleAsegaEvents(asega);
    if (FAsegaGone(asega))
        return;
    int wrapped = FWrapAsegaTime(asega, &asega->tLocal, &asega->svt);
    if (wrapped) {
        if (asega->grf & 8)
            asega->iea = asega->svt <= 0.0f ? asega->aseg->count : 0;
    }
    if (wrapped) {
        asega->Message(3, asega);
        if (FAsegaGone(asega))
            return;
    }
    HandleAsegaEvents(asega);
    if (FAsegaGone(asega))
        return;
    if (wrapped && (asega->grf & 0x38) == 0)
        RetractAsega(asega);
    for (Hook *hook = asega->hooks; hook != 0; hook = hook->next)
        hook->listener->Notify(hook->arg, 0, asega->tLocal, asega->svt);
}
