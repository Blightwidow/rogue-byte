struct SL { char pad[0xC]; void *owner; };
struct WR { char pad[0x8F0]; char list[4]; };
extern "C" void AppendSlEntry(char *, SL *);
void func_0022B7A0(WR *wr, SL *entry)
{
    AppendSlEntry(wr->list, entry);
    entry->owner = wr;
}
