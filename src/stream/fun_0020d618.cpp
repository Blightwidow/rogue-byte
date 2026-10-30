extern "C" { void Flush__5OSTRM(void *); void __builtin_delete(void *); }
extern "C" void func_0020D618(void *self, int flags)
{
    Flush__5OSTRM(self);
    if (flags & 1) __builtin_delete(self);
}
