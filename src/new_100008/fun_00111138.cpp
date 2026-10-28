extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CEB78;
void *func_00111138(void)
{
    int *object = (int *)__builtin_new(0x160);
    *(char **)((char *)object + 0xC) = &D_002CEB78;
    object[0] = 0;
    object[1] = 0;
    return object;
}
