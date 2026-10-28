struct OXA {
    char pad[0x70];
    long flags;
};
struct SO {
    char pad[0xEC];
    OXA *oxa;
};
extern "C" int GetSoNoXpsAll(SO *so)
{
    if (so->oxa == 0)
        return 1;
    return (int)(so->oxa->flags >> 2) & 1;
}
