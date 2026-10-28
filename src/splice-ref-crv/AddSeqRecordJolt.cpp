extern "C" void *PjsgeAllocJsg(void *, int);
extern "C" void AddSeqRecordJolt(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 50) + 0x10) = value;
}
