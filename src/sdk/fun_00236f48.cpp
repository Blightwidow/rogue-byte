extern "C" {
struct Node_236F48 { int key; char pad4[0x34]; Node_236F48 *next; };
struct Group_236F48 { char pad0[8]; Node_236F48 *head; char padC[8]; Group_236F48 *next; };
struct Owner_236F48 { char pad0[0x28]; Group_236F48 *groups; };
Node_236F48 *func_00236F48(int key, Owner_236F48 *owner) {
    Group_236F48 *group;
    Node_236F48 *node;
    for (group = owner->groups; group != 0; group = group->next) {
        for (node = group->head; node != 0; node = node->next) {
            if (node->key == key) {
                return node;
            }
        }
    }
    return 0;
}
}
