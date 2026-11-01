struct GVT { char pad[0x50]; short delta; short index; void (*fn)(void *); };
struct GOAL { char pad[0xC]; GVT *vt; };
struct GOALSTACK { char pad0[4]; int cgoal; GOAL *agoal[1]; };
extern "C" void GoalStack_Update(GOALSTACK *stack)
{
    int igoal = stack->cgoal;
    igoal--;
    for (; igoal >= 0; igoal--) {
        GOAL *goal = stack->agoal[igoal];
        goal->vt->fn((char *)goal + goal->vt->delta);
    }
}
