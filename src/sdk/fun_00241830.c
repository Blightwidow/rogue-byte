extern int func_00239450(void);
extern int func_002394A0(void);

int func_00241830(volatile unsigned int *channelControl)  // volatile-ok: pointer to a DMA channel control register (register block)
{
    int interruptsWereEnabled;
    unsigned int enabler;
    unsigned int old;

    interruptsWereEnabled = func_00239450();
    enabler = *(volatile unsigned int *)0x1000F520;
    if (!(enabler & 0x10000)) {
        *(volatile unsigned int *)0x1000F590 = enabler | 0x10000;
    }
    (void)*(volatile unsigned int *)0x1000E000;
    old = *channelControl;
    *channelControl = old & 0xFFFFFEFF;
    *(volatile unsigned int *)0x1000F590 = enabler;
    if (interruptsWereEnabled) {
        func_002394A0();
    }
    return old;
}
