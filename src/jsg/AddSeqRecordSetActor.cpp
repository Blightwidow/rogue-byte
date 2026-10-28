extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordSetActor(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 8, 1) + 0x10) = value;
}
