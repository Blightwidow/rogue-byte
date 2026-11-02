struct TICK { char pad[0x50]; unsigned long last; int wraps; };
extern "C" long TickReadCount(TICK *tick)
{
    unsigned long count;
    asm volatile("mfc0 %0, $9" : "=r"(count));
    count = count & 0xFFFFFFFFUL;
    if (count < tick->last)
        tick->wraps = tick->wraps + 1;
    tick->last = count;
    return ((long)tick->wraps << 32) | count;
}
