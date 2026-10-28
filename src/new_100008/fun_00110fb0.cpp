extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002DC210;
void *func_00110FB0(void)
{
    int *object = (int *)__builtin_new(0x140);
    *(char **)((char *)object + 0xC) = &D_002DC210;
    object[0] = 0;
    object[1] = 0;
    return object;
}
