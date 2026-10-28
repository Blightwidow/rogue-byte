void func_001A6E38(char *self, int flag)
{
    unsigned long *word = (unsigned long *)(self + 0x28);
    *word = (*word & 0xFBFFFFFFFFFFFFFFUL) | ((unsigned long)(flag & 1) << 58);
}
