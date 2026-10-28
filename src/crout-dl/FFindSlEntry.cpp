struct SL { int first; char *last; int ib; };
int FFindSlEntry(SL *list, char *pv)
{
    int found = 0;
    if (*(int *)(pv + list->ib) != 0 || list->last == pv)
        found = 1;
    return found;
}
