// SPDX-License-Identifier: GPL-3.0-or-later
typedef int s32;
extern "C" {
struct Element { char bytes[0x20]; };
struct Holder {
    s32 first;
    s32 second;
    s32 pad8;
    void *vtable;
    char pad10[0x50];
    Element elements[6];
};
extern char D_002D5120[];
void *__builtin_new(s32);
void func_002562A8(Element *);
Holder *func_00112B30(void) {
    s32 remaining = 5;
    Holder *holder = (Holder *)__builtin_new(0x160);
    holder->first = 0;
    holder->second = 0;
    holder->vtable = D_002D5120;
    Element *element = holder->elements;
    do {
        remaining -= 1;
        func_002562A8(element);
        element += 1;
    } while (remaining != -1);
    return holder;
}
}
