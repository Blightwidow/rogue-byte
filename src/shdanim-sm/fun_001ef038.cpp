struct Link { char pad0[0x14]; Link *next; char pad1[0x20 - 0x18]; int count; };
struct Owner { char pad0[0x10]; int target; Link *first; char pad1[0x1C - 0x18]; int active; };
extern "C" {
int FIsBasicDerivedFrom(int, int);
void RemoveGuardBusyGoal(int);
void func_001EF038(Owner *owner) {
    if (owner->active != 0) {
        owner->active = 0;
        if (FIsBasicDerivedFrom(owner->target, 0x38) != 0) {
            RemoveGuardBusyGoal(owner->target);
        }
        Link *link = owner->first;
        if (link != 0) {
            do {
                link->count = link->count - 1;
                link = link->next;
            } while (link != 0);
        }
    }
}
}
