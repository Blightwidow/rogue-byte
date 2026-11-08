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
// collector mark (bit 31), the same layout UnlinkPairNode (0x2550F8) uses. Both loops compute the next node
// into its own temp (retail's v0/s2) and then copy it to the cursor, so each has a `next` local; loop 2
// keeps the node it frees apart from the cursor. Still differs (score 6): the index shift goes to $a0
// instead of reusing the loaded word's $v0 (both loops), and in loop 1 the mark store's `and`/`sll` sit
// in the other order around the delay slot; the shift form (`links >> 16 & 0x1FFF`) fixes those but
// moves the pool to $v0 (score 12).
extern "C" void SweepPairs(void) {
    PairNode2577E0 *current;
    for (current = B_002DD280; current != B_002DD288;) {
        if (current->links.mark != g_2dd598[0])
            current->links.mark = g_2dd598[0];
        unsigned nextIndex = current->links.nextIndex;
        unsigned nextPool = current->links.nextPool;
        PairNode2577E0 *next;
        if (nextIndex == 0 && nextPool == 0)
            next = 0;
        else
            next = B_00452098[nextPool] + nextIndex;
        current = next;
    }
    while (current != 0) {
        PairNode2577E0 *node = current;
        PairNode2577E0 *next;
        unsigned nextIndex = node->links.nextIndex;
        unsigned nextPool = node->links.nextPool;
        if (nextIndex == 0 && nextPool == 0)
            next = 0;
        else
            next = B_00452098[nextPool] + nextIndex;
        current = next;
        if (node->links.mark != g_2dd598[0]) {
            UnlinkPairNode(node);
            FreeSlotheapPv(&B_004520A8, node);
        }
    }
}
