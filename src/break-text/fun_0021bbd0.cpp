struct So { char pad[0x15C]; void *hier; };
extern "C" void AddSoLoHierarchy(So *);
extern "C" void func_0021BC08(So *);
void func_0021BBD0(So *so)
{
    AddSoLoHierarchy(so);
    if (so->hier) func_0021BC08(so);
}
