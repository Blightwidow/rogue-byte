extern "C" {
void *eh_context_static(void);
extern void *(*D_002C60BC)(void);
void *eh_context_initialize(void) {
    D_002C60BC = eh_context_static;
    return (*D_002C60BC)();
}
}
