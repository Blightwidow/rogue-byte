struct DL { int first; int last; int ib; };
void PrependDlEntry(DL *list, char *pv)
{
    int ib = list->ib;
    int first = list->first;
    int *pdle = (int *)(pv + ib);
    if (first == 0) {
        list->last = (int)pv;
        list->first = (int)pv;
    } else {
        pdle[0] = first;
        first += ib;
        *(int *)(first + 4) = (int)pv;
        list->first = (int)pv;
    }
}
