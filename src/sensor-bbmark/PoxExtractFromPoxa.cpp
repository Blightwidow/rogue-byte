// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct Node { char pad0[4]; Node *next; char pad8[4]; int key; };
struct Poxa { char pad0[0x60]; int key; };
struct Pox { char pad0[0x64]; Node *head; };
Node *PoxExtractFromPoxa(Poxa *unused, Pox *pox, Poxa *poxa) {
    Node *node = pox->head;
    int key = poxa->key;
    if (node != 0) {
        Node **link = &node->next;
        if (node->key == key) {
            pox->head = node->next;
        } else {
            while ((node = node->next) != 0) {
                if (node->key == key) {
                    *link = node->next;
                    break;
                }
                link = &node->next;
            }
        }
    }
    return node;
}
}
