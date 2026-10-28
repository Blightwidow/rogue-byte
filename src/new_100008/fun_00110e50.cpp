extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D52B0;
void *func_00110E50(void)
{
    int *object = (int *)__builtin_new(0x130);
    *(char **)((char *)object + 0xC) = &D_002D52B0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
