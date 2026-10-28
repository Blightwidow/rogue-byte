extern "C" void *PjsgeAllocJsg(void *, int, int);
extern "C" void AddSeqRecordRevokeConfrontCamera(void *jsg, int value)
{
    *(int *)((char *)PjsgeAllocJsg(jsg, 58, 1) + 0x10) = value;
}
