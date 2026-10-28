extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CE828;
void *func_00111170(void)
{
    int *object = (int *)__builtin_new(0xf0);
    *(char **)((char *)object + 0xC) = &D_002CE828;
    object[0] = 0;
    object[1] = 0;
    return object;
}
