extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordWaitForMusic(void *jsg, float value)
{
    *(float *)((char *)PjsgeAllocJsg(jsg, 78, 0) + 0x10) = value;
}
