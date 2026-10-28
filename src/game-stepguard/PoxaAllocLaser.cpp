struct SO { char pad[0x70]; unsigned long flags; };
extern "C" SO *PoxaAllocSo(void);
extern "C" SO *PoxaAllocLaser(void)
{
    SO *so = PoxaAllocSo();
    so->flags |= 0x20;
    return so;
}
