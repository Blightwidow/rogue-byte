extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CFA10;
void *func_001133C0(void)
{
    int *object = (int *)__builtin_new(0xE0);
    *(char **)((char *)object + 0xC) = &D_002CFA10;
    object[0] = 0;
    object[1] = 0;
    return object;
}
