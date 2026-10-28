extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordDropBomb(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 81, 0) + 0x10) = value;
}
