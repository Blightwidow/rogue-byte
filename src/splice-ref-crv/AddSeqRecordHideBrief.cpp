extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordHideBrief(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 84, 1) + 0x10) = value;
}
