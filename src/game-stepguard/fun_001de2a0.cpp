struct SO { char pad[0x148]; unsigned long flags; };
extern "C" void InitSo(SO *);
extern "C" void func_001DE2A0(SO *so)
{
    InitSo(so);
    so->flags |= 0x400000000UL;
}
