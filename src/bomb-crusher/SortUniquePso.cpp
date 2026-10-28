#include "sly2.h"
extern "C" void func_0013B7A0();
extern "C" void qsort(void *, int, int, int (*)(const void *, const void *));
void SortUniquePso(void *unused, int *pcount, int *apso)
{
    int count = *pcount;
    if (count >= 2) {
        qsort(apso, count, 4, (int (*)(const void *, const void *))func_0013B7A0);
        int *last = apso; int *end = apso + count;
        for (int *next = apso; next < end; next++) { if (*last != *next) { last++; *last = *next; } }
        *pcount = (last - apso) + 1;
    }
}
