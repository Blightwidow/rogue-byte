extern "C" {
extern void (*D_002C60BC)(void);
void eh_context_static(void);
}
void eh_context_initialize(void) {
    void (*handler)(void) = eh_context_static;
    D_002C60BC = handler;
    handler();
}
