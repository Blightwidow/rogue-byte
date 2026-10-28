extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D0420;
void *func_001134D8(void)
{
    int *object = (int *)__builtin_new(0x40);
    *(char **)((char *)object + 0xC) = &D_002D0420;
    object[0] = 0;
    object[1] = 0;
    return object;
}
