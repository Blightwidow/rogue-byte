// SPDX-License-Identifier: GPL-3.0-or-later
struct HDR_1D7D30 { int count; unsigned char *pb; };
struct LAYOUT_1D7D30 { char pad[0x5400]; int last; int sum; };
static inline int SumBytes(unsigned char *pb, int cb)
{
    int sum = 0;
    for (; cb != 0; cb--)
        sum += *pb++;
    return sum;
}
extern "C" int FSaveDataMatchesLayout(HDR_1D7D30 *phdr, LAYOUT_1D7D30 *playout)
{
    int sum = SumBytes(phdr->pb, phdr->count * 10);
    int f = 0;
    if (*(unsigned short *)(phdr->pb + phdr->count * 10 - 6) == playout->last)
        f = sum == playout->sum;
    return f;
}
