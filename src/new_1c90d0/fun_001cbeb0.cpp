extern "C" void InitGuard(void *);
extern "C" void func_001CBEB0(char *self)
{
    InitGuard(self);
    *(int *)(self + 0x4A4) = 1;
}
