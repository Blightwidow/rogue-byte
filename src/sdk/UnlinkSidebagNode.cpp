// SPDX-License-Identifier: GPL-3.0-or-later
struct Links255DE8 {
    unsigned prevIndex : 13;
    unsigned prevPool : 2;
    unsigned unused15 : 1;
    unsigned nextIndex : 13;
    unsigned nextPool : 2;
    unsigned unused31 : 1;
};
struct PairNode255DE8 {
    int pad0;
    Links255DE8 links;
    int pad8[1];
};
extern "C" {
extern PairNode255DE8 *B_002DD2C0;
extern PairNode255DE8 *B_002DD2C8;
extern PairNode255DE8 *B_002DD2CC;
extern PairNode255DE8 *B_00452138[];

void UnlinkSidebagNode(PairNode255DE8 *node) {
    PairNode255DE8 *prev;
    PairNode255DE8 *next;
    unsigned prevIndex = node->links.prevIndex;
    unsigned prevPool = node->links.prevPool;
    if (prevIndex == 0 && prevPool == 0)
        prev = 0;
    else
        prev = B_00452138[prevPool] + prevIndex;
    unsigned nextIndex = node->links.nextIndex;
    unsigned nextPool = node->links.nextPool;
    if (nextIndex == 0 && nextPool == 0)
        next = 0;
    else
        next = B_00452138[nextPool] + nextIndex;
    if (node == B_002DD2C8)
        B_002DD2C8 = next;
    if (prev) {
        prev->links.nextIndex = node->links.nextIndex;
        prev->links.nextPool = node->links.nextPool;
    } else if (node == B_002DD2C0) {
        B_002DD2C0 = next;
    } else if (node == B_002DD2CC) {
        B_002DD2CC = next;
    }
    if (next) {
        next->links.prevIndex = node->links.prevIndex;
        next->links.prevPool = node->links.prevPool;
    }
}
}
