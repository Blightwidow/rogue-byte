struct Node127DB8 { int pad0; int pad4; int key; char value[8]; Node127DB8 *next; };
struct Tree127DB8 {
    int pad0;
    int pad4;
    int count;
    Tree127DB8 *items[4];
    Node127DB8 *head;
    int flag;
};
extern "C" void *PrefFindBinding__6CFrameUii(Tree127DB8 *self, int key, int flag)
{
    void *found = 0;
    Node127DB8 *node;
    int index;

    self->flag = 1;
    for (node = self->head; node != 0; node = node->next) {
        if (node->key == key) {
            found = &node->value;
            goto done;
        }
    }
    if (flag != 0) {
        for (index = 0; index < self->count; index++) {
            Tree127DB8 *child = self->items[index];
            if (child->flag == 0) {
                found = PrefFindBinding__6CFrameUii(child, key, flag);
                if (found != 0)
                    goto done;
            }
        }
    }
done:
    self->flag = 0;
    return found;
}
