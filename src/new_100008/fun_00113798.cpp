extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CFEA0;
void *func_00113798(void)
{
    int *object = (int *)__builtin_new(0x30);
    *(char **)((char *)object + 0xC) = &D_002CFEA0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
