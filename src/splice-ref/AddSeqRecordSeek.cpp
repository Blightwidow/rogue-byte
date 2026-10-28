extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordSeek(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 20, 1) + 0x10) = value;
}
