struct DL { int first; int last; int ib; };
extern "C" int CPvDl__FP2DL(DL *list)
{
    int count = 0;
    for (char *pv = (char *)list->first; pv != 0; pv = *(char **)(pv + list->ib))
        count++;
    return count;
}
