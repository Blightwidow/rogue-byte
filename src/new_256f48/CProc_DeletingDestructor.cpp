struct Pair;
struct CPairPtr { Pair *p; };
struct Pair { int count; int pad4; char ref[8]; CPairPtr next; };
struct Frame { int count; };
struct Proc { int pad0; int pad4; Frame *frame; int pad0c; int pad10; Pair *pair; Pair *pairLast; };
extern "C" {
void CPairPtr_Destructor(CPairPtr *, int);
void CRef_Destruct(void *);
void UnlinkPairNode(Pair *);
void UnlinkProcNode(Proc *);
void CFrame_DeletingDestructor(Frame *, int);
void FreeSlotheapPv(void *, void *);
extern char B_004520A8[];
extern char B_00452120[];
}
extern "C" void CProc_DeletingDestructor(Proc *self, int flags)
{
    Pair *pair = self->pairLast;
    if (pair != 0) {
        if (--pair->count == 0) {
            CPairPtr_Destructor(&pair->next, 2);
            CRef_Destruct(pair->ref);
            UnlinkPairNode(pair);
            FreeSlotheapPv(B_004520A8, pair);
        }
    }
    pair = self->pair;
    if (pair != 0) {
        if (--pair->count == 0) {
            CPairPtr_Destructor(&pair->next, 2);
            CRef_Destruct(pair->ref);
            UnlinkPairNode(pair);
            FreeSlotheapPv(B_004520A8, pair);
        }
    }
    Frame *frame = self->frame;
    if (frame != 0) {
        if (--frame->count == 0) CFrame_DeletingDestructor(frame, 3);
    }
    UnlinkProcNode(self);
    if (flags & 1) FreeSlotheapPv(B_00452120, self);
}
