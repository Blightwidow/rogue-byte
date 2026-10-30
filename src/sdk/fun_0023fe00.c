typedef struct Node_23FE00 Node_23FE00;
struct Node_23FE00 {
    int flag;
    int pad4;
    int key;
    int arg;
    int pad10;
    Node_23FE00 *next;
};
void free(int);
void func_00240328(void);
extern Node_23FE00 *B_00450278;
Node_23FE00 *func_0023FE00(int key) {
    Node_23FE00 **link = &B_00450278;
    Node_23FE00 *node;
    while (*link != 0) {
        node = *link;
        if (node->key == key) {
            *link = node->next;
            if (node->flag != 0) {
                free(node->arg);
            }
            return node;
        }
        link = &node->next;
    }
    func_00240328();
}
