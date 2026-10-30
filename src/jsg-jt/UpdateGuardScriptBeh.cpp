struct Guard_1713E8;
struct GuardVt_1713E8 { char pad0[0x78]; short delta; short pad1; void (*fn)(char *, void *); };
struct GuardNode_1713E8 { char pad[0x18]; GuardNode_1713E8 *next; };
struct Guard_1713E8 { char pad0[0xC]; GuardVt_1713E8 *vt; char pad1[0x28]; GuardNode_1713E8 *node; };
extern "C" {
int FGuardScriptWaiting(Guard_1713E8 *);
void func_001EEF98();
void UpdateGuardScriptBeh(Guard_1713E8 *self) {
    func_001EEF98();
    if (self->node != 0) {
        do {
            if (FGuardScriptWaiting(self) != 0)
                break;
            GuardNode_1713E8 *next = self->node->next;
            self->node = next;
            if (next == 0)
                break;
            self->vt->fn((char *)self + self->vt->delta, next);
        } while (self->node != 0);
    }
}
}
