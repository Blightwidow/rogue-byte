extern void func_00252358();
extern long func_00251FC8(char *mpeg);
unsigned func_00252148(char *mpeg, unsigned count)
{
    unsigned bits;
    unsigned command;
    unsigned mode;
    func_00252358();
    if (*(int *)(mpeg + 0x828) != 0 || *(int *)(mpeg + 0x84C) < (int)count) {
        *(volatile unsigned *)0x10002000 = 0x40000000;
        *(int *)(mpeg + 0x828) = 0;
        *(unsigned *)(mpeg + 0x82C) = 0x40000000;
        *(int *)(mpeg + 0x848) = func_00251FC8(mpeg);
    }
    *(int *)(mpeg + 0x84C) = 0x20;
    bits = *(unsigned *)(mpeg + 0x848);
    command = count | 0x40000000;
    *(volatile unsigned *)0x10002000 = command;
    mode = command & 0xF0000000;
    *(unsigned *)(mpeg + 0x82C) = mode;
    count = bits >> (0x20 - count);
    if (mode == 0x20000000 || mode == 0x30000000 || mode == 0x40000000)
        *(int *)(mpeg + 0x828) = 0;
    else
        *(int *)(mpeg + 0x828) = 1;
    *(int *)(mpeg + 0x848) = func_00251FC8(mpeg);
    return count;
}
