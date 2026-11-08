// SPDX-License-Identifier: GPL-3.0-or-later
struct Links256120 {
    unsigned prevIndex : 13;
    unsigned prevPool : 2;
    unsigned unused15 : 1;
    unsigned nextIndex : 13;
    unsigned nextPool : 2;
    unsigned unused31 : 1;
};
struct PairNode256120 {
    int pad0;
    Links256120 links;
    int pad8[3];
};
extern "C" {
extern PairNode256120 *B_002DD2D0;
extern PairNode256120 *B_002DD2D8;
extern PairNode256120 *B_002DD2DC;
extern PairNode256120 *B_00452160[];

void func_00256120(PairNode256120 *node) {
    PairNode256120 *prev;
    PairNode256120 *next;
    unsigned prevIndex = node->links.prevIndex;
    unsigned prevPool = node->links.prevPool;
    if (prevIndex == 0 && prevPool == 0)
        prev = 0;
    else
        prev = B_00452160[prevPool] + prevIndex;
    unsigned nextIndex = node->links.nextIndex;
    unsigned nextPool = node->links.nextPool;
    if (nextIndex == 0 && nextPool == 0)
        next = 0;
    else
        next = B_00452160[nextPool] + nextIndex;
    if (node == B_002DD2D8)
        B_002DD2D8 = next;
    if (prev) {
        prev->links.nextIndex = node->links.nextIndex;
        prev->links.nextPool = node->links.nextPool;
    } else if (node == B_002DD2D0) {
        B_002DD2D0 = next;
    } else if (node == B_002DD2DC) {
        B_002DD2DC = next;
    }
    if (next) {
        next->links.prevIndex = node->links.prevIndex;
        next->links.prevPool = node->links.prevPool;
    }
}
}
