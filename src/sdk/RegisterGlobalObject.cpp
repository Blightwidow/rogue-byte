struct GlobalObjectNode {
    int first;
    int second;
    int object;
    int objectCopy;
    int third;
    GlobalObjectNode *next;
};
extern "C" {
extern GlobalObjectNode *B_00450278;
void RegisterGlobalObject(int object, GlobalObjectNode *node) {
    node->object = object;
    node->objectCopy = object;
    node->second = 0;
    node->first = 0;
    node->third = 0;
    node->next = B_00450278;
    B_00450278 = node;
}
}
