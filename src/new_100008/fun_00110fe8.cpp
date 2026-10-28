extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CC7B0;
void *func_00110FE8(void)
{
    int *object = (int *)__builtin_new(0x2d0);
    *(char **)((char *)object + 0xC) = &D_002CC7B0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
