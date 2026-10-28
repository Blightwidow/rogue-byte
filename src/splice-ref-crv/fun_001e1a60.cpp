extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void func_001E1A60(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 87, 1) + 0x10) = value;
}
