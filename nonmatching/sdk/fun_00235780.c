int func_00235780(int ch)
{
    while (*(volatile unsigned int *)0x1000F130 & 0x8000) {
    }
    *(volatile unsigned char *)0x1000F180 = ch;
    return ch;
}
