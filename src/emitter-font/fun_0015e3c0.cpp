struct Entry { char pad[12]; };
extern "C" Entry *func_0015E3C0(char *base, int oid)
{
    return (Entry *)(base + 0x1838) + ((oid * 0x95675) & 0x1FF);
}
