extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordRetractMusic(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 77, 1) + 0x10) = value;
}
