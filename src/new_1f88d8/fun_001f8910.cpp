#include "sly2.h"
struct ACT { int kind; char pad4[8]; int priority; ACT *next; };
struct XF { char pad[0x90]; ACT *first; };
struct XFREF { char pad[0x20]; int alo; XF *xf; };
extern "C" void RemoveXfAct(int, XF *, ACT *);
extern "C" void FreeAct(ACT *);
extern "C" void ResortXfActList(int, XF *);
extern "C" void SetXfKind(int, XF *, int);
extern "C" void WakeXf(int, XF *);

ACT *func_001F8910(XFREF *ref, int kind, int xfk, int priority)
{
    ACT *act = ref->xf->first;
    if (act) {
        do {
            if (act->kind == kind) {
                if (xfk == -1) {
                    RemoveXfAct(ref->alo, ref->xf, act);
                    FreeAct(act);
                    return 0;
                }
                if (priority != act->priority) {
                    act->priority = priority;
                    ResortXfActList(ref->alo, ref->xf);
                }
                if (act == ref->xf->first) {
                    SetXfKind(ref->alo, ref->xf, xfk);
                    WakeXf(ref->alo, ref->xf);
                }
                return act;
            }
            act = act->next;
        } while (act);
    }
    return 0;
}
