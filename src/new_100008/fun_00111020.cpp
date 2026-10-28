extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002C9C20;
void *func_00111020(void)
{
    int *object = (int *)__builtin_new(0x2d0);
    *(char **)((char *)object + 0xC) = &D_002C9C20;
    object[0] = 0;
    object[1] = 0;
    return object;
}
