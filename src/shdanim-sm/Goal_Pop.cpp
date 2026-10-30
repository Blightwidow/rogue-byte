struct VT_1EF0D8 { char pad[0x48]; short delta; short pad2; void (*fn)(void *); };
struct Goal_1EF0D8 { char pad[0xC]; VT_1EF0D8 *vt; char *owner; };
extern "C" void GoalStack_Pop(char *);
extern "C" void Goal_Pop(Goal_1EF0D8 **slot)
{
    Goal_1EF0D8 *goal = *slot;
    if (goal != 0) {
        char *stack = goal->owner + 0x26C;
        goal->vt->fn((char *)goal + goal->vt->delta);
        GoalStack_Pop(stack);
        *slot = 0;
    }
}
