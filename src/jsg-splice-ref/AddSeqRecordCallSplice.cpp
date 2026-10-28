extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordCallSplice(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 9, 1) + 0x10) = value;
}
