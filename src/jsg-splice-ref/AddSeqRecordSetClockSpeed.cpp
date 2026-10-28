extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordSetClockSpeed(void *jsg, float value)
{
    *(float *)((char *)PjsgeAllocJsg(jsg, 16, 1) + 0x10) = value;
}
