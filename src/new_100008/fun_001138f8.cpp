extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CC3C0;
void *func_001138F8(void)
{
    int *object = (int *)__builtin_new(0xA0);
    *(char **)((char *)object + 0xC) = &D_002CC3C0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
