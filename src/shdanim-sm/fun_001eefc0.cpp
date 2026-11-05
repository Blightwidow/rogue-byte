struct Node { char pad0[0x14]; Node *next; char pad18[8]; int count; };
struct Guard { char pad0[0x10]; int owner; Node *first; int f18; int done; };
extern "C" int FIsBasicDerivedFrom(int, int);
extern "C" void AddGuardBusyGoal(int);
extern "C" void func_001EEFC0(Guard *self) {
    if (self->done == 0) {
        self->done = 1;
        if (FIsBasicDerivedFrom(self->owner, 0x38) != 0) {
            AddGuardBusyGoal(self->owner);
        }
        Node *node = self->first;
        if (node != 0) {
            do {
                node->count = node->count + 1;
                node = node->next;
            } while (node != 0);
        }
    }
}
