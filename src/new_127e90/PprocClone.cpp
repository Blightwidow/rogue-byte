#include "sly2.h"
struct Proc { int cref; int pad4; int frame; int pad0xC; int pad0x10; int params; int body; };
struct Frame;
struct HP { Proc *p; int pad[3]; };
extern "C" {
Proc *PprocNew(void);
void func_00257038(void *h, Proc *p);
void CFramePtr_Assign(void *h, void *f);
void PairHandle_Assign(void *h, int p);
void CProc_DeletingDestructor(Proc *p, int f);
}
extern "C" void *PprocClone(void *result, Proc *psource, Frame *pframe)
{
    HP h;
    func_00257038(&h, PprocNew());
    if (pframe != 0)
        CFramePtr_Assign(&h.p->frame, pframe);
    else
        CFramePtr_Assign(&h.p->frame, (void *)psource->frame);
    PairHandle_Assign(&h.p->params, psource->params);
    h.p->pad0xC = psource->pad0xC;
    h.p->pad0x10 = psource->pad0x10;
    PairHandle_Assign(&h.p->body, psource->body);
    func_00257038(result, h.p);
    Proc *t = h.p;
    if (t && --t->cref == 0)
        CProc_DeletingDestructor(t, 3);
    return result;
}
