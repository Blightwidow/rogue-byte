struct DL { int first; int last; int ib; };
int FFindDlEntry(DL *list, char *pv)
{
    int found = 0;
    if (*(int *)(pv + list->ib) != 0 || list->last == (int)pv)
        found = 1;
    return found;
}
