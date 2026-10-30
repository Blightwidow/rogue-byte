extern "C" int FActiveCplcy(void *);
extern char B_002DE2E0[];
extern int g_2dfbc0;
extern "C" int func_0019EEF0(char **arg0, int arg1) {
    if (arg1 == 3) {
        int result = 0;
        if (*(int *)(*arg0 + 0x12F0) != 0) {
            if (g_2dfbc0 & 2)
                result = FActiveCplcy(B_002DE2E0) == 0;
        }
        return result;
    }
    return 0;
}
