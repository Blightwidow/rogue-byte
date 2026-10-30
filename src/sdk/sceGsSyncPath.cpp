extern "C" {
int sceGsSyncPath(void) {
    int busy;
    do {
        int vuStatus;
        busy = 0;
        if (*(volatile unsigned int *)0x10009000 & 0x100) {
            busy = 1;
        }
        if (*(volatile unsigned int *)0x1000A000 & 0x100) {
            busy |= 2;
        }
        if (*(volatile unsigned int *)0x10003C00 & 3) {
            busy |= 4;
        }
        asm volatile("cfc2.ni %0, $vi29" : "=r"(vuStatus));
        if (vuStatus & 0x100) {
            busy |= 8;
        }
        if (*(volatile unsigned int *)0x10003020 & 0xC00) {
            busy |= 0x10;
        }
    } while (busy != 0);
    return 0;
}
}
