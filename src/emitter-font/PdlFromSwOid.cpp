struct Entry { char pad[12]; };
extern "C" Entry *PdlFromSwOid(char *base, int oid)
{
    return (Entry *)(base + 0x38) + ((oid * 0x95675) & 0x1FF);
}
