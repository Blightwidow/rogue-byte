#include "sly2.h"
struct B8 { char b[8]; };
struct OBJ { virtual void v0(); int pad; };
typedef void (OBJ::*PMF)(int);
struct CRef { int tagk; int n; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct CFrame { int refs; };
struct CB { OBJ *plo; B8 pmf; int nArg; CB *pnext; };
struct TIMED { float time; CFrame **pobject; CPair *ppair; int state; };
struct SLH { char b[0x18]; };
struct SWX {
    char pad[0x39F0];
    TIMED *ptimed;
    int ptimedTail; int ptimedPad;
    SLH heapTimed;
    char pad2[0x3C90 - 0x39FC - 0x18];
    SLH heapCb;
    CB *pcbFirst;
    int pcbTail;
    int pcbPad;
};
struct CFrameHandle { CFrame *pframe; int pad; };
extern "C" {
int FIsSlEmpty(void *);
void ClearSl(void *);
void FreeSlotheapPv(void *, void *);
void RemoveSlEntry(void *, void *);
CFrame *PframeNew(void);
void func_00257058(CFrame **, CFrame *);
void EvalScriptCall(void *, CPair *, CFrame *, CRef *);
void CFrame_DeletingDestructor(CFrame *, int);
void CPairPtr_Destructor(CPair **, int);
void CRef_Destruct(CRef *);
void UnlinkPairNode(CPair *);
extern char B_004520A8[];
}
extern float g_2dded0;
static inline void ReleaseFrame(CFrame *frame)
{
    if (frame != 0) {
        if (--frame->refs == 0)
            CFrame_DeletingDestructor(frame, 3);
    }
}
extern "C" void UpdateSwCallbacks(SWX *psw)
{
    while (!FIsSlEmpty(&psw->pcbFirst)) {
        CB *pcb = psw->pcbFirst;
        ClearSl(&psw->pcbFirst);
        for (; pcb != 0; ) {
            PMF pmf;
            *(B8 *)&pmf = pcb->pmf;
            (pcb->plo->*pmf)(pcb->nArg);
            CB *pnext = pcb->pnext;
            FreeSlotheapPv(&psw->heapCb, pcb);
            pcb = pnext;
        }
    }
    TIMED *ptimed = psw->ptimed;
    if (ptimed == 0 || g_2dded0 < ptimed->time)
        return;
    {
        do {
            CFrame **pobject = ptimed->pobject;
            ptimed->state = -1;
            if (pobject != 0) {
                EvalScriptCall(pobject, ptimed->ppair, *pobject, 0);
            } else {
                CFrameHandle handle;
                func_00257058(&handle.pframe, PframeNew());
                EvalScriptCall(psw, ptimed->ppair, handle.pframe, 0);
                ReleaseFrame(handle.pframe);
            }
            RemoveSlEntry(&psw->ptimed, ptimed);
            CPair *ppair = ptimed->ppair;
            if (--ppair->cref == 0 && ppair != 0) {
                CPairPtr_Destructor(&ppair->next, 2);
                CRef_Destruct(&ppair->ref);
                UnlinkPairNode(ppair);
                FreeSlotheapPv(B_004520A8, ppair);
            }
            FreeSlotheapPv(&psw->heapTimed, ptimed);
            ptimed = psw->ptimed;
        } while (ptimed != 0 && !(g_2dded0 < ptimed->time));
    }
}
