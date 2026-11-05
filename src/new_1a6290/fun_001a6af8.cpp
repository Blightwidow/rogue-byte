struct Node { char pad[0x10]; Node *parent; };
int func_001A6AF8(Node *start, Node *target)
{
    Node *node = start;
    if (node != 0 && node != target) {
        for (node = node->parent; node != 0 && node != target; node = node->parent) {
        }
    }
    return node != 0;
}
