struct DL { int first; int last; int ib; };
void AppendDlEntry(DL *list, char *pv)
{
    int ib = list->ib;
    int last = list->last;
    int *pdle = (int *)(pv + ib);
    if (last == 0) {
        list->last = (int)pv;
        list->first = (int)pv;
    } else {
        pdle[1] = last;
        last += ib;
        *(int *)last = (int)pv;
        list->last = (int)pv;
    }
}
