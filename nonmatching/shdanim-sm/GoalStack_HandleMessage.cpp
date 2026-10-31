struct VT { char pad[0x68]; short delta; short idx; int (*fn)(void *, int, int); };
struct Obj { char pad[0xC]; VT *vt; };
struct Stack { int pad; int count; Obj *items[1]; };
extern "C" void GoalStack_HandleMessage(Stack *stack, int a, int b) {
    int index = stack->count;
    Obj **cursor = &stack->items[index];
    for (index--; index >= 0; index--) {
        cursor--;
        Obj *obj = *cursor;
        if (obj->vt->fn((void *)((int)obj + obj->vt->delta), a, b)) break;
    }
}
