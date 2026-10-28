// 0x1B9880 SetMurrayStateF
// Script operation 0x57: puts Murray in state 0xF.
extern "C" void SetMurrayState(void* pmurray, int state);

void func_001B9880(void* pmurray)
{
    SetMurrayState(pmurray, 0xF);
}
