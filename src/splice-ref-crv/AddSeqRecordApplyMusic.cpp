extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordApplyMusic(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 76, 1) + 0x10) = value;
}
