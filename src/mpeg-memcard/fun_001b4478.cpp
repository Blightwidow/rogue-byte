extern "C" void InitRenderNodeStack(void *);
extern "C" void RenderGlobsetTree(void *, void *);
extern "C" void RenderGlobset(void *, int, int, float, float);

void func_001B4478(char *arg0) {
    char sp[0x410];

    if (*(int *)(arg0 + 0xC8) != 0) {
        InitRenderNodeStack(sp);
        RenderGlobsetTree(sp, arg0 + 0x80);
    } else {
        RenderGlobset(arg0 + 0x80, 0, 0, 1.0f, 1.0f);
    }
}
