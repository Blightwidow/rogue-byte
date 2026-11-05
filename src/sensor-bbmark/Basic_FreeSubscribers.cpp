// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct Subscriber { char pad0[8]; Subscriber *next; };
struct Basic { char pad0[8]; Subscriber *subscribers; };
extern char B_003E1144[];
void FreeSlotheapPv(void *, void *);
void Basic_FreeSubscribers(Basic *basic) {
    Subscriber *current = basic->subscribers;
    if (current != 0) {
        Subscriber *freed;
        do {
            freed = current;
            current = current->next;
            FreeSlotheapPv(B_003E1144, freed);
        } while (current != 0);
    }
    basic->subscribers = 0;
}
}
