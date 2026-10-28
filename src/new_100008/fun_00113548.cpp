extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D01A0;
void *func_00113548(void)
{
    int *object = (int *)__builtin_new(0x50);
    *(char **)((char *)object + 0xC) = &D_002D01A0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
