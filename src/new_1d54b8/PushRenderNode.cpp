struct Stack { unsigned count; int nodes[256]; };
void PushRenderNode(Stack *stack, int node) {
    unsigned n = stack->count;
    if (n < 0x100) {
        stack->nodes[n] = node;
        stack->count = n + 1;
    }
}
