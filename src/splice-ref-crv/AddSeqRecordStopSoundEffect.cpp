extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordStopSoundEffect(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 55, 1) + 0x10) = value;
}
