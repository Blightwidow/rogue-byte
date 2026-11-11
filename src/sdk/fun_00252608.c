#include "ps2inline.h"
extern int func_00239450();
extern void func_002394A0();
extern char D_451E80[];
struct Chain {
    unsigned head;
    int unused;
    unsigned first[4];
    unsigned second[0x10];
    char gap[0x12C - 0x58];
    int count;
    char tail[0x10];
};
struct Dev {
    char gap0[0x5A0];
    struct Chain chain[2];
};
void func_00252608(char *base)
{
    struct Dev *dev = (struct Dev *)base;
    int index;
    int count;
    int flag;
    unsigned long *tag;
    int slot;
    if (*(int *)(base + 0x87C) == 0) {
    index = *(int *)(base + 0x820);
    count = dev->chain[index].count;
    tag = (unsigned long *)(((unsigned)D_451E80 & 0xFFFFFFF) | 0x20000000);
    for (slot = 0; slot < count; slot++) {
        unsigned first = dev->chain[index].first[slot];
        unsigned second = dev->chain[index].second[slot];
        unsigned long head = ((unsigned long)(first & 0xFFFFFFF) << 32) | 0x30000000UL;
        unsigned long last = (slot == count - 1) ? 0 : 3;
        unsigned long tail = ((unsigned long)(second & 0xFFFFFFF) << 32) | (last << 28);
        head |= 0x30;
        tail |= 0x30;
        tag[0] = head;
        tag[2] = tail;
        tag += 4;
    }
    flag = func_00239450();
    MemoryBarrier();
    *(volatile unsigned *)0x1000D480 = dev->chain[*(int *)(base + 0x820)].head;
    *(volatile unsigned *)0x1000D430 = (unsigned)D_451E80;
    *(volatile unsigned *)0x1000D420 = 0;
    *(volatile unsigned *)0x1000D400 = 0x105;
    if (flag) {
        func_002394A0();
        return;
    }
    }
}
