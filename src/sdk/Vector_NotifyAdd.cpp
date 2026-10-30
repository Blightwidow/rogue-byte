struct VT_256588 { char pad[0x10]; short delta; short unused; void (*fn)(void *, int); };
struct Node_256588 { char pad[4]; Node_256588 *next; VT_256588 *vt; };
struct Owner_256588 { char pad[0x28]; Node_256588 *head; };
extern "C" {
void Vector_NotifyAdd(Owner_256588 *self, int arg1) {
    Node_256588 *node = self->head;
    if (node != 0) {
        do {
            node->vt->fn((char *)node + node->vt->delta, arg1);
            node = node->next;
        } while (node != 0);
    }
}
}
