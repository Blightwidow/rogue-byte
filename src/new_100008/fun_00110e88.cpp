extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002DB518;
void *func_00110E88(void)
{
    int *object = (int *)__builtin_new(0x100);
    *(char **)((char *)object + 0xC) = &D_002DB518;
    object[0] = 0;
    object[1] = 0;
    return object;
}
