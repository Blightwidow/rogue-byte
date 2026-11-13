// SPDX-License-Identifier: GPL-3.0-or-later
struct Links2577E0 {
    unsigned prevIndex : 13;
    unsigned prevPool : 2;
    unsigned unused15 : 1;
    unsigned nextIndex : 13;
    unsigned nextPool : 2;
    unsigned mark : 1;
};
struct PairNode2577E0 {
    int pad0;
    Links2577E0 links;
    int pad8[3];
};
struct SlotHeap2577E0;
extern "C" {
extern PairNode2577E0 *B_002DD280;
extern PairNode2577E0 *B_002DD288;
extern PairNode2577E0 *B_00452098[];
extern SlotHeap2577E0 B_004520A8;
extern unsigned g_2dd598[];
void UnlinkPairNode(PairNode2577E0 *);
void FreeSlotheapPv(SlotHeap2577E0 *, void *);
}

// Retail reads the pair links at +4 as bitfields: next index (bits 16-28), next pool (bits 29-30) and the
// collector mark (bit 31), the same layout UnlinkPairNode (0x2550F8) uses. The next node comes from a helper
// that takes index and pool as arguments: the extracted fields land in fresh temps, as in retail.
static inline PairNode2577E0 *PairNodeFromLink(unsigned index, unsigned pool) {
    if (index == 0 && pool == 0)
        return 0;
    return B_00452098[pool] + index;
}

extern "C" void SweepPairs(void) {
    PairNode2577E0 *current;
    for (current = B_002DD280; current != B_002DD288;) {
        if (current->links.mark != g_2dd598[0])
            current->links.mark = g_2dd598[0];
        PairNode2577E0 *next;
        next = PairNodeFromLink(current->links.nextIndex, current->links.nextPool);
        current = next;
    }
    while (current != 0) {
        PairNode2577E0 *node = current;
        PairNode2577E0 *next;
        next = PairNodeFromLink(node->links.nextIndex, node->links.nextPool);
        current = next;
        if (node->links.mark != g_2dd598[0]) {
            UnlinkPairNode(node);
            FreeSlotheapPv(&B_004520A8, node);
        }
    }
}
