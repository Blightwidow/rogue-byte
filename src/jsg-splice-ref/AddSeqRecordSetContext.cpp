extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordSetContext(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 12, 1) + 0x10) = value;
}
