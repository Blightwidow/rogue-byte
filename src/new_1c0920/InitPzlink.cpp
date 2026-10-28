extern "C" void InitLo(void *);
extern "C" void InitPzlink(char *self)
{
    InitLo(self);
    *(int *)(self + 0x120) = -1;
    *(int *)(self + 0x150) = -1;
}
