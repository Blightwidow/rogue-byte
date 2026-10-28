#include "sly2.h"
struct SEQ { char pad[0x38]; int on; int flags; };
extern "C" char B_003DD490;
extern "C" void ClearHandsOff(void *, int);
extern "C" void SetHandsOff(void *, int);
extern "C" void DecrementSwHandsOff__FP2SW(void *);
extern "C" void IncrementSwHandsOff__FP2SW(void *);
extern "C" void SetSeqnodeHandsOff(SEQ *seq, int on, int grf)
{
    if (on == 0) {
        if (seq->on == 0) return;
        goto off;
    }
    if (seq->on != 0) {
        if (grf == seq->flags) return;
        ClearHandsOff(&B_003DD490, seq->flags);
        DecrementSwHandsOff__FP2SW(&B_003DD490);
    }
    SetHandsOff(&B_003DD490, grf);
    IncrementSwHandsOff__FP2SW(&B_003DD490);
    seq->flags = grf;
    goto done;
off:
    ClearHandsOff(&B_003DD490, seq->flags);
    DecrementSwHandsOff__FP2SW(&B_003DD490);
    seq->flags = grf;
done:
    seq->on = on;
}
