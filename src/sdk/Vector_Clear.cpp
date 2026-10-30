struct VT_256658 { char pad[8]; short delta; short unused; void (*fn)(void *); };
struct Node_256658 { char pad[4]; Node_256658 *next; VT_256658 *vt; };
struct Owner_256658 { char pad[0x10]; char sub[0x18]; Node_256658 *head; };
extern "C" {
void func_00116D28(void *);
void Vector_Clear(Owner_256658 *self) {
    func_00116D28(self->sub);
    Node_256658 *node = self->head;
    if (node != 0) {
        do {
            node->vt->fn((char *)node + node->vt->delta);
            node = node->next;
        } while (node != 0);
    }
}
}
