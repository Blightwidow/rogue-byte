extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordWaitForVoice(void *jsg, float value)
{
    *(float *)((char *)PjsgeAllocJsg(jsg, 82, 0) + 0x10) = value;
}
