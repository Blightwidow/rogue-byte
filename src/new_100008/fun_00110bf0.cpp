extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D5DC8;
void *func_00110BF0(void)
{
    int *object = (int *)__builtin_new(0x110);
    *(char **)((char *)object + 0xC) = &D_002D5DC8;
    object[0] = 0;
    object[1] = 0;
    return object;
}
