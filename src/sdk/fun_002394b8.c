struct SemaParam {
    int attribute;
    int initCount;
    int maxCount;
    int word3;
    int word4;
    const char *name;
    int word6;
    int word7;
};
extern int D_002C4AB8;
extern int D_002C4ABC;
extern int CreateSema(struct SemaParam *param);
void func_002394B8(void)
{
    struct SemaParam first;
    struct SemaParam second;
    first.initCount = 1;
    first.maxCount = 1;
    first.name = "SceKernelLibc";
    second.initCount = 1;
    second.maxCount = 1;
    second.name = "SceKernelLibcEh";
    D_002C4AB8 = CreateSema(&first);
    D_002C4ABC = CreateSema(&second);
}
