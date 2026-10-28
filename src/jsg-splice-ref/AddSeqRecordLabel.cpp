extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordLabel(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 19, 1) + 0x10) = value;
}
