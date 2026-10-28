struct CRef { int tagk; int pad[3]; CRef &operator=(const CRef &); };
struct Frame { int refs; int pad[8]; int flag; };
struct Entry { void *ppair; Frame *pframe; };
struct Block { char pad[8]; Entry *aentry; };
extern "C" Frame *PframeNew();
extern "C" void func_00257058(Frame **, Frame *);
extern "C" void func_00259A88(Frame *);
extern "C" void RefEval(CRef *, void *, Frame *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void CFrame_DeletingDestructor(Frame *, int);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);

inline void ReleaseFrame(Frame *frame)
{
    if (frame != 0) {
        if (--frame->refs == 0)
            CFrame_DeletingDestructor(frame, 3);
    }
}

CRef *RunSpliceBlockEntry(CRef *result, void *sw, Block *block, int index)
{
    struct L { CRef eval; Frame *handle; int pad[3]; CRef value; } l;
    l.eval.tagk = -1;
    if (block->aentry[index].ppair != 0 && block->aentry[index].pframe == 0) {
        Frame *fresh = PframeNew();
        func_00257058(&l.handle, fresh);
        func_00259A88(l.handle);
        l.handle->flag = 1;
        RefEval(&l.value, block->aentry[index].ppair, l.handle);
        l.eval = l.value;
        CRef_Destruct(&l.value);
        l.handle->refs++;
        block->aentry[index].pframe = l.handle;
        ReleaseFrame(l.handle);
    }
    CRef_Destruct(&l.eval);
    SetTag__4CRef4TAGK(&l.eval, 0x24);
    CRef_CopyConstruct(result, &l.eval);
    CRef_Destruct(&l.eval);
    return result;
}
