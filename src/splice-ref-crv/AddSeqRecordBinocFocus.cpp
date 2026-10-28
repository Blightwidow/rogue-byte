extern "C" void *PjsgeAllocJsg(void *, int);
extern "C" void AddSeqRecordBinocFocus(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 62) + 0x10) = value;
}
