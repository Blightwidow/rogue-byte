extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordBinocZoom(void *jsg, int flag, float value)
{
    *(float *)((char *)PjsgeAllocJsg(jsg, 64, flag) + 0x10) = value;
}
