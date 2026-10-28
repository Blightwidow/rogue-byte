extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002CE4D0;
void *func_001111E0(void)
{
    int *object = (int *)__builtin_new(0x110);
    *(char **)((char *)object + 0xC) = &D_002CE4D0;
    object[0] = 0;
    object[1] = 0;
    return object;
}
