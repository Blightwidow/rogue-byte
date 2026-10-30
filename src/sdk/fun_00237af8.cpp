extern "C" {
struct SemaParam_237AF8 { int attr; int initCount; int maxCount; int field0C; int field10; const char *name; };
int CreateSema(SemaParam_237AF8 *);
extern int D_002C4A84;
void func_00237AF8(void) {
    SemaParam_237AF8 param;
    if (D_002C4A84 == -1) {
        param.maxCount = 1;
        param.initCount = 1;
        param.name = "SceStdioFioSema";
        D_002C4A84 = CreateSema(&param);
    }
}
}
