extern "C" {
void func_00167E58(unsigned int);
void iFlushCache(int);
int Vif1InterruptHandler(int cause)
{
    func_00167E58(0x1100C320);
    iFlushCache(0);
    *(volatile int *)0x10003C10 = 8;
    asm volatile("sync");
    asm volatile("ei");
    return -1;
}
}
