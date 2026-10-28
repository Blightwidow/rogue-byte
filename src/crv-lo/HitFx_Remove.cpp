#include "sly2.h"
struct HF;
struct VT {
    char pad0[8];
    short d8; short i8; void (*f8)(void *);
    short d10; short i10; void (*f10)(void *);
    short d18; short i18; void (*f18)(void *, int, int, int, int, int);
    short d20; short i20; void (*f20)(void *, int, void *);
};
struct HF { char pad[0xC]; VT *vptr; };
struct REFH { HF *p; };
extern "C" int FHitFxGone(HF *);
extern "C" void RemoveDlEntry(void *, HF *);
extern char B_003E148C;
extern "C" void HitFx_Remove(HF *pfx)
{
    if (FHitFxGone(pfx) == 0) {
        REFH ref;
        ref.p = pfx;
        asm volatile("" : : "m"(ref));
        pfx->vptr->f8((char *)pfx + pfx->vptr->d8);
        pfx->vptr->f20((char *)pfx + pfx->vptr->d20, 0xF, pfx);
        if (FHitFxGone(pfx) != 0) {
            ref.p->vptr->f10((char *)ref.p + ref.p->vptr->d10);
        } else {
            RemoveDlEntry(&B_003E148C, pfx);
            pfx->vptr->f18((char *)pfx + pfx->vptr->d18, 3, 0, 0, 0, 0);
            pfx->vptr->f10((char *)pfx + pfx->vptr->d10);
            ref.p->vptr->f10((char *)ref.p + ref.p->vptr->d10);
        }
    }
}
