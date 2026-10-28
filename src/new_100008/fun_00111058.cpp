extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002DC6F0;
void *func_00111058(void)
{
    int *object = (int *)__builtin_new(0x190);
    *(char **)((char *)object + 0xC) = &D_002DC6F0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
