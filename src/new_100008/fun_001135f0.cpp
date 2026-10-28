extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CDD40;
void *func_001135F0(void)
{
    int *object = (int *)__builtin_new(0x60);
    *(char **)((char *)object + 0xC) = &D_002CDD40;
    object[0] = 0;
    object[1] = 0;
    return object;
}
