extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CDBA0;
void *func_00110E18(void)
{
    int *object = (int *)__builtin_new(0x180);
    *(char **)((char *)object + 0xC) = &D_002CDBA0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
