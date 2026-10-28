extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordSetPlayer(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 7, 1) + 0x10) = value;
}
