extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002DD090;
void *func_00110B10(void)
{
    int *object = (int *)__builtin_new(0xe0);
    *(char **)((char *)object + 0xC) = &D_002DD090;
    object[0] = 0;
    object[1] = 0;
    return object;
}
