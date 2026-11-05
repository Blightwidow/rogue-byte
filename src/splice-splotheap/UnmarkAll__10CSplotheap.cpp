#include "sly2.h"
struct Node { char pad[0x10]; int mark; int pad2; Node *next; };
struct CSplotheap { Node *head; };
extern "C" void UnmarkAll__10CSplotheap(CSplotheap *self)
{
    Node *node = self->head;
    while (node) {
        node->mark = 0;
        node = node->next;
    }
}
