#include "sly2.h"
struct CRef;
extern "C" void CRef_Destruct(CRef *);
struct CRef { int tagk; int n; CRef &operator=(const CRef &); ~CRef() { CRef_Destruct(this); } };
struct CRefRaw { int tagk; int n; };
struct P { int pad0; int pad4; int tagk; P *pv; P *next; };
struct CFrame { int refs; };
extern "C" void CFrame_DeletingDestructor(CFrame *, int);
struct CFramePtr {
    CFrame *p; int pad[3];
    ~CFramePtr() {
        CFrame *pf = p;
        if (pf != 0) {
            int refs = pf->refs - 1;
            pf->refs = refs;
            if (refs == 0)
                CFrame_DeletingDestructor(pf, 3);
        }
    }
};
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void RefEval(CRefRaw *, P *, CFrame *);
extern "C" CFrame *PframeNew();
extern "C" void CFramePtr_Assign(CFramePtr *, CFrame *);
extern "C" void CFrame_RefAddBinding(CRefRaw *, CFrame *, int, CRef *);
extern "C" void bevy_splice_frame_set_parent(CFrame *, CFrame *);
extern "C" void CRefRaw_Destruct(CRefRaw *) asm("CRef_Destruct");
extern "C" CRef *RefEvalLet(CRef *pref, P *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refInit;
    CRef refBinding;
    CFramePtr pframeLet;
    CRefRaw refTemp;
    pframeLet.p = 0;
    refResult.tagk = -1;
    refInit.tagk = -1;
    refBinding.tagk = -1;
    P *pbindings = ppair->pv->next;
    P *pbody;
    if (pbindings->tagk == 0x1F) {
        CFrame *pnew = PframeNew();
        CFramePtr_Assign(&pframeLet, pnew);
        P *pentry = pbindings->pv;
        if (pentry != 0) {
        CRef *pinit = &refInit;
        CRefRaw *ptemp = &refTemp;
        CRef *pbinding = &refBinding;
        for (; pentry != 0; pentry = pentry->next) {
            P *psym = pentry->pv;
            RefEval(ptemp, psym->next, pframe);
            *pinit = *(CRef *)ptemp;
            CRefRaw_Destruct(ptemp);
            CFrame_RefAddBinding(ptemp, pframeLet.p, (int)psym->pv, pinit);
            *pbinding = *(CRef *)ptemp;
            CRefRaw_Destruct(ptemp);
        }
        }
        bevy_splice_frame_set_parent(pframeLet.p, pframe);
    } else {
        CFramePtr_Assign(&pframeLet, pframe);
    }
    P *pnode = pbindings->next;
    if (pnode != 0) {
        do {
            RefEval(&refTemp, pnode, pframeLet.p);
            refResult = *(CRef *)&refTemp;
            CRefRaw_Destruct(&refTemp);
            pnode = pnode->next;
        } while (pnode != 0);
    }
    CRef_CopyConstruct(pref, &refResult);
    return pref;
}
