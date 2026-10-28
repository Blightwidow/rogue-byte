extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CFFA0;
void *func_001136D0(void)
{
    int *object = (int *)__builtin_new(0x40);
    *(char **)((char *)object + 0xC) = &D_002CFFA0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
