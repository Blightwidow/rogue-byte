typedef struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    int attribute;
    const char *option;
} SemaParam;

extern int CreateSema(SemaParam *param);
extern int D_002C6760;
extern int D_002C6768;
extern int D_002C676C;
extern int D_002C6770;
extern int D_002C6774;

void func_00241A30(void)
{
    SemaParam param;

    if (D_002C6768 == -1 || D_002C676C == -1 || D_002C6770 == -1) {
        param.initCount = 1;
        param.maxCount = 1;
        param.option = "SceCdNcmdSema";
        D_002C6768 = CreateSema(&param);
        param.option = "SceCdScmdSema";
        D_002C676C = CreateSema(&param);
        param.option = "SceCdRcmdSema";
        D_002C6770 = CreateSema(&param);
        param.option = "SceCdCallbackSema";
        param.initCount = 0;
        D_002C6760 = CreateSema(&param);
        D_002C6774 = 0;
    }
}
