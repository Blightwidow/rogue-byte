extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordTakeOutBomb(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 80, 0) + 0x10) = value;
}
