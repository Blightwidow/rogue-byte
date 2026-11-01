// SPDX-License-Identifier: GPL-3.0-or-later
struct Links2550F8 {
    unsigned prevIndex : 13;
    unsigned prevPool : 2;
    unsigned unused15 : 1;
    unsigned nextIndex : 13;
    unsigned nextPool : 2;
    unsigned unused31 : 1;
};
struct PairNode2550F8 {
    int pad0;
    Links2550F8 links;
    int pad8[3];
};
extern "C" {
extern PairNode2550F8 *B_002DD280;
extern PairNode2550F8 *B_002DD288;
extern PairNode2550F8 *B_002DD28C;
extern PairNode2550F8 *B_00452098[];

void UnlinkPairNode(PairNode2550F8 *node) {
    PairNode2550F8 *prev;
    PairNode2550F8 *next;
    unsigned prevIndex = node->links.prevIndex;
    unsigned prevPool = node->links.prevPool;
    if (prevIndex == 0 && prevPool == 0)
        prev = 0;
    else
        prev = B_00452098[prevPool] + prevIndex;
    unsigned nextIndex = node->links.nextIndex;
    unsigned nextPool = node->links.nextPool;
    if (nextIndex == 0 && nextPool == 0)
        next = 0;
    else
        next = B_00452098[nextPool] + nextIndex;
    if (node == B_002DD288)
        B_002DD288 = next;
    if (prev) {
        prev->links.nextIndex = node->links.nextIndex;
        prev->links.nextPool = node->links.nextPool;
    } else if (node == B_002DD280) {
        B_002DD280 = next;
    } else if (node == B_002DD28C) {
        B_002DD28C = next;
    }
    if (next) {
        next->links.prevIndex = node->links.prevIndex;
        next->links.prevPool = node->links.prevPool;
    }
}
}
