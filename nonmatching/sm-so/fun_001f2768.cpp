struct SO {
    char pad[0xD0];
    unsigned long flags;
};
extern "C" void func_001F2768(SO *so, int flag)
{
    so->flags = (so->flags & ~0x400000000UL) | ((unsigned long)(flag & 1) << 34);
}
