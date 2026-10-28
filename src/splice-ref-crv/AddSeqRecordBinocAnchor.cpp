extern "C" void *PjsgeAllocJsg(void *, int);
extern "C" void AddSeqRecordBinocAnchor(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 61) + 0x10) = value;
}
