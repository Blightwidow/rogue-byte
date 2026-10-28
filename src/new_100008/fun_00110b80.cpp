extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002DC070;
void *func_00110B80(void)
{
    int *object = (int *)__builtin_new(0x120);
    *(char **)((char *)object + 0xC) = &D_002DC070;
    object[0] = 0;
    object[1] = 0;
    return object;
}
