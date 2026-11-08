// SPDX-License-Identifier: GPL-3.0-or-later
struct Links255AB0 {
    unsigned prevIndex : 13;
    unsigned prevPool : 2;
    unsigned unused15 : 1;
    unsigned nextIndex : 13;
    unsigned nextPool : 2;
    unsigned unused31 : 1;
};
struct PairNode255AB0 {
    int pad0;
    Links255AB0 links;
    int pad8[5];
};
extern "C" {
extern PairNode255AB0 *B_002DD2B0;
extern PairNode255AB0 *B_002DD2B8;
extern PairNode255AB0 *B_002DD2BC;
extern PairNode255AB0 *B_00452110[];

void UnlinkProcNode(PairNode255AB0 *node) {
    PairNode255AB0 *prev;
    PairNode255AB0 *next;
    unsigned prevIndex = node->links.prevIndex;
    unsigned prevPool = node->links.prevPool;
    if (prevIndex == 0 && prevPool == 0)
        prev = 0;
    else
        prev = B_00452110[prevPool] + prevIndex;
    unsigned nextIndex = node->links.nextIndex;
    unsigned nextPool = node->links.nextPool;
    if (nextIndex == 0 && nextPool == 0)
        next = 0;
    else
        next = B_00452110[nextPool] + nextIndex;
    if (node == B_002DD2B8)
        B_002DD2B8 = next;
    if (prev) {
        prev->links.nextIndex = node->links.nextIndex;
        prev->links.nextPool = node->links.nextPool;
    } else if (node == B_002DD2B0) {
        B_002DD2B0 = next;
    } else if (node == B_002DD2BC) {
        B_002DD2BC = next;
    }
    if (next) {
        next->links.prevIndex = node->links.prevIndex;
        next->links.prevPool = node->links.prevPool;
    }
}
}
