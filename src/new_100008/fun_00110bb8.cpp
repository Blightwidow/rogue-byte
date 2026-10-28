extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D6E08;
void *func_00110BB8(void)
{
    int *object = (int *)__builtin_new(0x100);
    *(char **)((char *)object + 0xC) = &D_002D6E08;
    object[0] = 0;
    object[1] = 0;
    return object;
}
