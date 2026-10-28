struct Stack { int count; int nodes[256]; };
int PopRenderNode(Stack *stack) {
    int n = stack->count;
    if (n == 0) return 0;
    stack->count = n - 1;
    return stack->nodes[n - 1];
}
