extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002C9A80;
void *func_00110F08(void)
{
    int *object = (int *)__builtin_new(0xf0);
    *(char **)((char *)object + 0xC) = &D_002C9A80;
    object[0] = 0;
    object[1] = 0;
    return object;
}
