#include "sly2.h"
struct SEQ { char pad[0x24]; char *subject; int *lo; int *hi; int *cur; };
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void GoalStack_Clear(void *);
extern "C" void func_001E5570(SEQ *seq)
{
    int *cur = seq->cur;
    if (seq->lo < cur && cur < seq->hi) {
        int k = *cur;
        if (k == 0x27) goto a;
        if (k == 0x28) goto b;
        return;
    a:
        if (seq->subject != 0) {
            if (FIsBasicDerivedFrom(seq->subject, 0x34))
                GoalStack_Clear(seq->subject + 0x26C);
        }
        return;
    b:
        if (seq->subject != 0) {
            if (FIsBasicDerivedFrom(seq->subject, 0x34))
                GoalStack_Clear(seq->subject + 0x26C);
        }
    }
}
