// SPDX-License-Identifier: GPL-3.0-or-later
struct Links255438 {
    unsigned prevIndex : 13;
    unsigned prevPool : 2;
    unsigned unused15 : 1;
    unsigned nextIndex : 13;
    unsigned nextPool : 2;
    unsigned unused31 : 1;
};
struct PairNode255438 {
    int pad0;
    Links255438 links;
    int pad8[4];
};
extern "C" {
extern PairNode255438 *B_002DD290;
extern PairNode255438 *B_002DD298;
extern PairNode255438 *B_002DD29C;
extern PairNode255438 *B_004520C0[];

void UnlinkVarbNode(PairNode255438 *node) {
    PairNode255438 *prev;
    PairNode255438 *next;
    unsigned prevIndex = node->links.prevIndex;
    unsigned prevPool = node->links.prevPool;
    if (prevIndex == 0 && prevPool == 0)
        prev = 0;
    else
        prev = B_004520C0[prevPool] + prevIndex;
    unsigned nextIndex = node->links.nextIndex;
    unsigned nextPool = node->links.nextPool;
    if (nextIndex == 0 && nextPool == 0)
        next = 0;
    else
        next = B_004520C0[nextPool] + nextIndex;
    if (node == B_002DD298)
        B_002DD298 = next;
    if (prev) {
        prev->links.nextIndex = node->links.nextIndex;
        prev->links.nextPool = node->links.nextPool;
    } else if (node == B_002DD290) {
        B_002DD290 = next;
    } else if (node == B_002DD29C) {
        B_002DD29C = next;
    }
    if (next) {
        next->links.prevIndex = node->links.prevIndex;
        next->links.prevPool = node->links.prevPool;
    }
}
}
