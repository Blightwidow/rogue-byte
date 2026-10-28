#include "sly2.h"
struct SLOTHEAP;
struct Node { Node *next; Node *prev; char pad[4]; void *vtable; char pad2[0x10]; void *owner; void *part; char pad3[0x8]; };
extern SLOTHEAP B_003E15CC;
extern char D_002CA280[];
extern "C" void *PpartFindAlo(void *);
extern "C" void *PvAllocSlotheapImpl(SLOTHEAP *);
extern "C" Node *func_001F85E0(void *owner)
{
    void *part = PpartFindAlo(owner);
    if (!part) return 0;
    Node *node = (Node *)PvAllocSlotheapImpl(&B_003E15CC);
    memset(node, 0, 0x30);
    node->owner = owner;
    node->part = part;
    node->vtable = D_002CA280;
    node->next = 0;
    node->prev = 0;
    return node;
}
