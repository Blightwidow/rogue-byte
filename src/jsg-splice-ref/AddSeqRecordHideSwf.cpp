extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordHideSwf(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 15, 1) + 0x10) = value;
}
