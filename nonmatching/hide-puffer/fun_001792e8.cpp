extern "C" int func_001792E8(char *arg0)
{
    int state = *(int *)(arg0 + 0x4C);
    int result = 0;
    if (state < 2) {
        if (state >= 0) {
            result = 1;
            if (*(float *)(arg0 + 0xE0) < 0.0f)
                ; else
                result = 0;
        }
    }
    return result;
}
