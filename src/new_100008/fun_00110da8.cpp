extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D4DE0;
void *func_00110DA8(void)
{
    int *object = (int *)__builtin_new(0x1f0);
    *(char **)((char *)object + 0xC) = &D_002D4DE0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
