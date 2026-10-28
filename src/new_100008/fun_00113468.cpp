extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D4AF8;
void *func_00113468(void)
{
    int *object = (int *)__builtin_new(0x40);
    *(char **)((char *)object + 0xC) = &D_002D4AF8;
    object[0] = 0;
    object[1] = 0;
    return object;
}
