struct CQueueOutputIp1B2FD8 { int pad; };
extern "C" int CbWrite__15CQueueOutputIpuiPv(CQueueOutputIp1B2FD8 *self, unsigned size, unsigned address) {
    int count = size & 0xFFFFFFF0u;
    if (count > 0x1000) count = 0x1000;
    *(volatile unsigned *)0x1000B420 = (unsigned)count >> 4;
    *(volatile unsigned *)0x1000B410 = address & 0x0FFFFFFF;
    *(volatile unsigned *)0x1000B400 = 0x101;
    asm("sync");
    return count;
}
