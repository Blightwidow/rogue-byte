#include "sly2.h"
struct Aseg { char pad0[0x40]; unsigned grf; char pad44[0xA0 - 0x44]; int count; };
struct Asega;
struct AVT {
    char pad[8]; short addDelta; short addIndex; void (*addRef)(void *);
    short relDelta; short relIndex; void (*release)(void *);
    char pad18[8]; short msgDelta; short msgIndex; void (*message)(void *, int, void *);
};
struct LVT { char pad[0x10]; short delta; short index; void (*fn)(void *, void *, void *, float, float); };
struct Listener { LVT *vtable; };
struct Hook { Listener *listener; void *arg; char pad8[8]; Hook *next; };
struct Asega {
    char pad0[0xC]; AVT *vtable; char pad10[4]; Aseg *aseg; char pad18[4]; float tLocal; char pad20[0x38 - 0x20];
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
extern "C" void UpdateAsega(Asega *asega)
{
    Asega *hold;
    if (__builtin_fabsf(asega->svt) < 0.0001f)
        return;
    hold = asega;
    asm("" : : "r"(&hold));
    asega->vtable->addRef((int *)asega + asega->vtable->addDelta);
    unsigned grf = asega->aseg->grf;
    if ((grf ^ 1) & 1)
        grf = *(unsigned *)grf;
    float svtNow;
    float dtNow;
    if (grf & 0x100) {
        svtNow = asega->svt;
        dtNow = g_2ddf10;
    } else {
        svtNow = asega->svt;
        dtNow = g_2dded4;
    }
    *(volatile float *)&asega->tLocal = asega->tLocal + svtNow * dtNow;
    HandleAsegaEvents(asega);
    if (FAsegaGone(asega))
        { Asega *h = hold; h->vtable->release((char *)h + h->vtable->relDelta); return; }
    {
        int wrapped = FWrapAsegaTime(asega, &asega->tLocal, &asega->svt);
        if (wrapped) {
            if (asega->grf & 8) {
                int start;
                float svtNow2 = asega->svt;
                float zero;
                asm volatile("mtc1 $0, %0\n\tnop" : "=f" (zero));
                if (svtNow2 <= zero)
                    start = asega->aseg->count;
                else
                    start = 0;
                asega->iea = start;
            }
        }
        if (wrapped) {
            asega->vtable->message((char *)asega + asega->vtable->msgDelta, 3, asega);
            if (FAsegaGone(asega))
                { Asega *h = hold; h->vtable->release((char *)h + h->vtable->relDelta); return; }
        }
        HandleAsegaEvents(asega);
        if (FAsegaGone(asega))
            { Asega *h = hold; h->vtable->release((char *)h + h->vtable->relDelta); return; }
        if (wrapped && (asega->grf & 0x38) == 0)
            RetractAsega(asega);
        for (Hook *hook = asega->hooks; hook != 0; hook = hook->next) {
            Listener *listener = hook->listener;
            listener->vtable->fn((char *)listener + listener->vtable->delta, hook->arg, 0, asega->tLocal, asega->svt);
        }
    }
    Asega *h = hold;
    h->vtable->release((char *)h + h->vtable->relDelta);
}
