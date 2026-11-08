// SPDX-License-Identifier: GPL-3.0-or-later
struct RENDER_RECORD
{
    int bucket;
    float depth;
    int field8;
    int fieldC;
};
extern "C" {
void qsort(void *base, unsigned int count, unsigned int size, int (*compare)(const void *, const void *));
int func_00157A50(const void *, const void *);
int func_00157A98(const void *, const void *);
// Counting sort of render records into 26 buckets, then a depth qsort of a few buckets
// (func_00157A50 sorts by depth at +4 far to near, func_00157A98 near to far). Retail
// keeps the two record loops' counters in $a2 and the two bucket loops' counters in $t0:
// that is two loop variables, one for buckets and one for records; a single shared index
// gives every loop the same register. Retail zeroes the bucket ends from 25 down to 0.
int SortRenderRecords(int count, RENDER_RECORD *records, RENDER_RECORD **sorted, int *bucketStart, int *bucketEnd)
{
    int cursor[26];
    int bucket;
    int index;
    for (bucket = 25; bucket >= 0; bucket--)
        bucketEnd[bucket] = 0;
    for (index = 0; index < count; index++)
        bucketEnd[records[index].bucket]++;
    bucketStart[0] = 0;
    cursor[0] = 0;
    for (bucket = 1; bucket < 26; bucket++) {
        bucketStart[bucket] = bucketEnd[bucket - 1];
        bucketEnd[bucket] += bucketStart[bucket];
        cursor[bucket] = bucketStart[bucket];
    }
    for (index = 0; index < count; index++)
        sorted[cursor[records[index].bucket]++] = &records[index];
    qsort(sorted + bucketStart[5], bucketEnd[5] - bucketStart[5], 4, func_00157A50);
    qsort(sorted + bucketStart[6], bucketEnd[6] - bucketStart[6], 4, func_00157A50);
    qsort(sorted + bucketStart[10], bucketEnd[10] - bucketStart[10], 4, func_00157A50);
    qsort(sorted + bucketStart[1], bucketEnd[1] - bucketStart[1], 4, func_00157A50);
    qsort(sorted + bucketStart[2], bucketEnd[2] - bucketStart[2], 4, func_00157A50);
    qsort(sorted + bucketStart[25], bucketEnd[25] - bucketStart[25], 4, func_00157A50);
    qsort(sorted + bucketStart[21], bucketEnd[21] - bucketStart[21], 4, func_00157A98);
    return bucketEnd[25];
}
}
