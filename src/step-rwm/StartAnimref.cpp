struct VT { char pad[8]; short delta; short index; void (*fn)(void *); };
struct Inst { char pad[0xC]; VT *vt; };
struct Animref { int kind; void *pv; Inst *pinst; int n; };
extern "C" {
void ApplyAseg(void *, void *, float, float, int, Inst **);
void PsmaApplySmInternal_thunk(void *, void *, int, int, Inst **);
void StartJumpAnim(void *, void *, int, void *);
void StartDirAnim(void *, void *, int, void *);
}

static inline void Go(Inst *inst) { inst->vt->fn((char *)inst + inst->vt->delta); }

void StartAnimref(float gStart, Animref *ref, char *owner, int grf)
{
    switch (ref->kind) {
    case 0:
        ApplyAseg(ref->pv, owner, gStart, 1.0f, grf, &ref->pinst);
        Go(ref->pinst);
        break;
    case 1:
        PsmaApplySmInternal_thunk(ref->pv, owner, -1, grf, &ref->pinst);
        Go(ref->pinst);
        break;
    case 2:
        ref->pinst = (Inst *)(owner + 0xDB0);
        StartJumpAnim(ref->pv, owner, grf, ref->pinst);
        Go(ref->pinst);
        break;
    case 3:
        ref->pinst = (Inst *)(owner + 0xE20);
        StartDirAnim(ref->pv, owner, grf, ref->pinst);
        Go(ref->pinst);
        break;
    case -1:
        return;
    }
}
