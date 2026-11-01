// SPDX-License-Identifier: GPL-3.0-or-later
struct PairNode2577E0 {
    int pad0;
    unsigned links;
    int pad8[3];
};
struct SlotHeap2577E0;
extern "C" {
extern PairNode2577E0 *B_002DD280;
extern PairNode2577E0 *B_002DD288;
extern PairNode2577E0 *B_00452098[];
extern SlotHeap2577E0 B_004520A8;
extern int g_2dd598[];
void UnlinkPairNode(PairNode2577E0 *);
void FreeSlotheapPv(SlotHeap2577E0 *, void *);
}

static inline PairNode2577E0 *FirstNextPair2577E0(PairNode2577E0 *node) {
    unsigned index = (node->links >> 16) & 0x1FFF;
    unsigned pool = (node->links >> 29) & 3;
    if (index != 0 || pool != 0)
        return B_00452098[pool] + index;
    return 0;
}

static inline PairNode2577E0 *NextPair2577E0(PairNode2577E0 *node) {
    unsigned index = (node->links >> 16) & 0x1FFF;
    unsigned pool = (node->links >> 29) & 3;
    if (index == 0 && pool == 0)
        return 0;
    return B_00452098[pool] + index;
}

extern "C" void SweepPairs(void) {
    PairNode2577E0 *current = B_002DD280;
    if (current != B_002DD288) {
        do {
            if ((current->links >> 31) != g_2dd598[0])
                current->links = (current->links & 0x7FFFFFFF) | (g_2dd598[0] << 31);
            PairNode2577E0 *following = FirstNextPair2577E0(current);
            current = following;
        } while (current != B_002DD288);
    }
    PairNode2577E0 *node = current;
    while (node != 0) {
        PairNode2577E0 *next = NextPair2577E0(node);
        current = next;
        if ((node->links >> 31) != g_2dd598[0]) {
            UnlinkPairNode(node);
            FreeSlotheapPv(&B_004520A8, node);
        }
        node = current;
    }
}
