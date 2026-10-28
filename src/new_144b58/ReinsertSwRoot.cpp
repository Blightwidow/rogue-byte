void RemoveSwRoot(int, int);
void InsertDlEntryBefore(int, int, int);

void ReinsertSwRoot(int psw, int proot)
{
    RemoveSwRoot(psw, proot);
    InsertDlEntryBefore(psw + 0x20, *(int*)(psw + 0x39a4), proot);
}
