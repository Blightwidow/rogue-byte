extern "C" {
int func_00236960(const char *, ...);
int sceGsPutDrawEnv(unsigned long *draw) {
    unsigned int count = 0;
    while (*(volatile unsigned int *)0x1000A000 & 0x100) {
        if (count++ > 0x1000000) {
            func_00236960("sceGsPutDrawEnv: DMA Ch.2 does not terminate\r\n");
            return -1;
        }
    }
    *(volatile unsigned int *)0x1000A020 = (int)(*draw & 0x7FFF) + 1;
    unsigned int address = (unsigned int)draw;
    if ((address & 0x70000000) == 0x70000000) {
        *(volatile unsigned int *)0x1000A010 = (address & 0x0FFFFFFF) | 0x80000000;
    } else {
        *(volatile unsigned int *)0x1000A010 = address & 0x0FFFFFFF;
    }
    *(volatile unsigned int *)0x1000A000 = 0x101;
    return 0;
}
}
