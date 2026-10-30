struct Entry { int *pvalue; char pad4[0xC]; int flag; };
extern "C" {
int FFindSlEntry();
void AppendSlEntry(int, Entry *);
extern int B_002E0CB4;
void AddCode(int list, Entry *entry)
{
    if (FFindSlEntry() == 0) {
        AppendSlEntry(list, entry);
        if (*entry->pvalue == B_002E0CB4) entry->flag = 1; else entry->flag = 0;
    }
}
}
