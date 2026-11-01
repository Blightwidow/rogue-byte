struct VT { char pad[0x68]; short delta; short idx; int (*fn)(void *, int, int); };
struct Obj { char pad[0xC]; VT *vt; };
struct Stack { int pad; int count; Obj *items[1]; };
extern "C" void GoalStack_HandleMessage(Stack *stack, int a, int b) {
    int index = stack->count;
    while (--index >= 0) {
        Obj *obj = stack->items[index];
        VT *vt = obj->vt;
        if (vt->fn((char *)obj + vt->delta, a, b)) break;
    }
}
