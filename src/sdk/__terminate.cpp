extern "C" {
extern void (*D_002C60B8)(void);
void __terminate(void) {
    (*D_002C60B8)();
}
}
