typedef int QW __attribute__((mode(TI)));
struct Step { QW q[9]; };
struct TN { char pad[0x110]; int count; Step *steps; Step *current; int fixed; };
extern "C" void func_00221940(TN *);
extern Step D_002C4120;

extern "C" void func_00221818(TN *tn, int cid)
{
    func_00221940(tn);
    if (tn->count < 4) {
        Step *steps = tn->steps;
        for (int i = 0; i < tn->count; i++) {
            if (*(int *)&steps[i] == cid) {
                tn->current = &steps[i];
                return;
            }
        }
        if (tn->fixed != 0) {
            tn->current = steps;
            return;
        }
        int index = tn->count;
        tn->count = index + 1;
        Step *added = &steps[index];
        tn->current = added;
        if (tn->count >= 2)
            *added = steps[tn->count - 2];
        else
            *added = D_002C4120;
        *(int *)tn->current = cid;
    }
}
