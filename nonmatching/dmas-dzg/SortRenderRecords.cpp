// SPDX-License-Identifier: GPL-3.0-or-later
struct REC { int key; int pad[3]; };
extern "C" {
void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
int func_00157A50(const void *, const void *);
int func_00157A98(const void *, const void *);
int SortRenderRecords(int count, REC *prec, REC **psorted, int *pstart, int *pcount)
{
    int cursor[26];
    int *pzero = pcount + 25;
    int remaining = 25;
    do {
        *pzero = 0;
        remaining--;
        pzero--;
    } while (remaining >= 0);
    if (count > 0) {
        REC *pcounted = prec;
        int left = count;
        do {
            pcount[pcounted->key]++;
            left--;
            pcounted++;
        } while (left != 0);
    }
    pstart[0] = 0;
    cursor[0] = 0;
    int *pend = pcount + 1;
    int *pbegin = pstart + 1;
    int *pcursor = cursor + 1;
    int bins = 24;
    do {
        int ended = pend[-1];
        bins--;
        *pbegin = ended;
        pend[0] += ended;
        pend++;
        int begun = *pbegin;
        pbegin++;
        *pcursor = begun;
        pcursor++;
    } while (bins >= 0);
    if (count > 0) {
        REC *pplaced = prec;
        int left = count;
        do {
            left--;
            int *pslot = &cursor[pplaced->key];
            int slot = *pslot;
            psorted[slot] = pplaced;
            *pslot = slot + 1;
            pplaced++;
        } while (left != 0);
    }
    qsort(psorted + pstart[5], pcount[5] - pstart[5], 4, func_00157A50);
    qsort(psorted + pstart[6], pcount[6] - pstart[6], 4, func_00157A50);
    qsort(psorted + pstart[10], pcount[10] - pstart[10], 4, func_00157A50);
    qsort(psorted + pstart[1], pcount[1] - pstart[1], 4, func_00157A50);
    qsort(psorted + pstart[2], pcount[2] - pstart[2], 4, func_00157A50);
    qsort(psorted + pstart[25], pcount[25] - pstart[25], 4, func_00157A50);
    qsort(psorted + pstart[21], pcount[21] - pstart[21], 4, func_00157A98);
    return pcount[25];
}
}
