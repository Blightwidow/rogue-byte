extern "C" {
struct SemaParam_2374E0 { int attr; int initCount; int maxCount; int field0C; int field10; const char *name; };
int CreateSema(SemaParam_2374E0 *);
extern int D_002C4A88;
extern int D_002C4A8C;
void func_002374E0(void) {
    SemaParam_2374E0 param;
    if (D_002C4A88 == -1) {
        param.maxCount = 1;
        param.initCount = 1;
        param.name = "SceStdioIobSema";
        D_002C4A88 = CreateSema(&param);
        param.name = "SceStdioQueSema";
        D_002C4A8C = CreateSema(&param);
    }
}
}
