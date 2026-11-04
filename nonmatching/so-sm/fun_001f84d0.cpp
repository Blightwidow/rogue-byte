struct A { char pad[0x148]; unsigned long : 33; unsigned long flag : 1; };
extern "C" void func_001F84D0(A *self, int flag)
{
    self->flag = flag;
}
