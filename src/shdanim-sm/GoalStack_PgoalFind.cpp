struct Stack { int pad; int count; int items[1]; };
extern "C" int FIsBasicDerivedFrom(int, int);
extern "C" int GoalStack_PgoalFind(Stack *stack, int type) {
    for (int index = 0; index < stack->count; index++) {
        int item = stack->items[index];
        if (FIsBasicDerivedFrom(item, type)) return item;
    }
    return 0;
}
