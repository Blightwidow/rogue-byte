extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D2B18;
void *func_00110C60(void)
{
    int *object = (int *)__builtin_new(0x120);
    *(char **)((char *)object + 0xC) = &D_002D2B18;
    object[0] = 0;
    object[1] = 0;
    return object;
}
