struct Node { char pad0[0x44]; Node *next; };
struct Owner { char pad0[0xF0]; Node *first; int last; };
extern "C" int func_001FD080(Owner *owner, int target) {
    Node *node = owner->first;
    while (node != 0) {
        if ((int)node == target) {
            return 1;
        }
        node = node->next;
    }
    return (owner->last ^ target) == 0 ? 0 : 2;
}
