// SPDX-License-Identifier: GPL-3.0-or-later
struct Links255770 {
    unsigned prevIndex : 13;
    unsigned prevPool : 2;
    unsigned unused15 : 1;
    unsigned nextIndex : 13;
    unsigned nextPool : 2;
    unsigned unused31 : 1;
};
struct PairNode255770 {
    int pad0;
    Links255770 links;
    int pad8[8];
};
extern "C" {
extern PairNode255770 *B_002DD2A0;
extern PairNode255770 *B_002DD2A8;
extern PairNode255770 *B_002DD2AC;
extern PairNode255770 *B_004520E8[];

void UnlinkFrameNode(PairNode255770 *node) {
    PairNode255770 *prev;
    PairNode255770 *next;
    unsigned prevIndex = node->links.prevIndex;
    unsigned prevPool = node->links.prevPool;
    if (prevIndex == 0 && prevPool == 0)
        prev = 0;
    else
        prev = B_004520E8[prevPool] + prevIndex;
    unsigned nextIndex = node->links.nextIndex;
    unsigned nextPool = node->links.nextPool;
    if (nextIndex == 0 && nextPool == 0)
        next = 0;
    else
        next = B_004520E8[nextPool] + nextIndex;
    if (node == B_002DD2A8)
        B_002DD2A8 = next;
    if (prev) {
        prev->links.nextIndex = node->links.nextIndex;
        prev->links.nextPool = node->links.nextPool;
    } else if (node == B_002DD2A0) {
        B_002DD2A0 = next;
    } else if (node == B_002DD2AC) {
        B_002DD2AC = next;
    }
    if (next) {
        next->links.prevIndex = node->links.prevIndex;
        next->links.prevPool = node->links.prevPool;
    }
}
}
