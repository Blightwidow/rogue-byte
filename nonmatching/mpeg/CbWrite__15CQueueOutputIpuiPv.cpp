typedef unsigned int u32;
typedef int s32;
extern "C" {
void CbWrite__15CQueueOutputIpuiPv(void *self, s32 size, s32 address) {
    u32 *qwc = (u32 *)0x1000B420;
    u32 *madr = (u32 *)0x1000B410;
    u32 *chcr = (u32 *)0x1000B400;
    s32 count = size & 0xFFFFFFF0;
    if (count > 0x1000) count = 0x1000;
    *qwc = (u32)count >> 4;
    *madr = address & 0x0FFFFFFF;
    *chcr = 0x101;
    asm("sync");
}
}
