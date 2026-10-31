struct VT1_1725E0 { char pad[0x10]; short delta; short unused; void (*fn)(void *); };
struct VT2_1725E0 { char pad[0x8]; short delta; short unused; void (*fn)(void *); };
struct GOAL_1725E0 { char pad[0xC]; void *vt; };
struct SEARCHER_1725E0 { char pad[0x44]; GOAL_1725E0 *goal; int changed; };
extern "C" void SetSearchGoal(SEARCHER_1725E0 *self, GOAL_1725E0 *goal) {
    GOAL_1725E0 *old = self->goal;
    if (goal != old) {
        if (old != 0) {
            VT1_1725E0 *vt = (VT1_1725E0 *)old->vt;
            vt->fn((char *)old + vt->delta);
        }
        self->goal = goal;
        if (goal != 0) {
            VT2_1725E0 *vt = (VT2_1725E0 *)goal->vt;
            vt->fn((char *)goal + vt->delta);
        }
        self->changed = 1;
    }
}
