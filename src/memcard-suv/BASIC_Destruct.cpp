struct Varb { int count; int pad4; int pad8; char ref[8]; int next; };
struct Frame { int count; };
struct Sidebag { int count; int pad4; Varb *varb; };
struct Basic { Frame *frame; Sidebag *sidebag; };
extern "C" {
void VarbPtr_Destructor(void *, int);
void CRef_Destruct(void *);
void UnlinkVarbNode(Varb *);
void UnlinkSidebagNode(Sidebag *);
void CFrame_DeletingDestructor(Frame *, int);
void FreeSlotheapPv(void *, void *);
void __builtin_delete(void *);
extern char B_004520D0[];
extern char B_00452148[];
}
extern "C" void BASIC_Destruct(Basic *self, int flags)
{
    Sidebag *sidebag = self->sidebag;
    if (sidebag != 0) {
        if (--sidebag->count == 0) {
            Varb *varb = sidebag->varb;
            if (varb != 0) {
                if (--varb->count == 0) {
                    VarbPtr_Destructor(&varb->next, 2);
                    CRef_Destruct(varb->ref);
                    UnlinkVarbNode(varb);
                    FreeSlotheapPv(B_004520D0, varb);
                }
            }
            UnlinkSidebagNode(sidebag);
            FreeSlotheapPv(B_00452148, sidebag);
        }
    }
    Frame *frame = self->frame;
    if (frame != 0) {
        if (--frame->count == 0) CFrame_DeletingDestructor(frame, 3);
    }
    if (flags & 1) __builtin_delete(self);
}
