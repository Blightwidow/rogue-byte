extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordUnhide(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 27, 0) + 0x10) = value;
}
