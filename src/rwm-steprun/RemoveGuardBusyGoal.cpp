extern "C" void func_001A6CA8(void *, int);
struct Owner { char pad0[0xFFC]; int busy; };
void RemoveGuardBusyGoal(Owner *owner)
{
    int busy = owner->busy - 1;
    owner->busy = busy;
    if (busy == 0) func_001A6CA8(owner, 0);
}
