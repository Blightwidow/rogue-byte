// 0x1B2A80 CQueueOutputIop::Reset
extern "C" void Reset__15CQueueOutputIop(void *arg0)
{
    *(int *)((char *)arg0 + 0x24) = *(int *)((char *)arg0 + 0x18);
    *(int *)((char *)arg0 + 0x28) = 0;
    *(int *)((char *)arg0 + 0x20) = 0;
    *(int *)((char *)arg0 + 0x1C) = 0;
    int *field = (int *)((char *)arg0 + 0x2C);
    *field = 0;
}