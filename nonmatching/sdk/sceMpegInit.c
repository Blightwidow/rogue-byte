extern int func_00239450();
extern void func_002394A0();
extern void InitIpu();
int sceMpegInit(void)
{
    int flag = func_00239450();
    *(volatile unsigned *)0x1000F590 = *(volatile unsigned *)0x1000F520 | 0x10000;
    *(volatile unsigned *)0x1000B000 &= 0xFFFFFEFF;
    *(volatile unsigned *)0x1000B400 &= 0xFFFFFEFF;
    *(volatile unsigned *)0x1000F590 = *(volatile unsigned *)0x1000F520 & 0xFFFEFFFF;
    if (flag)
        func_002394A0();
    *(volatile unsigned *)0x1000B020 = 0;
    *(volatile unsigned *)0x1000B420 = 0;
    InitIpu();
    return 1;
}
