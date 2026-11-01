struct SLOT_1B1BF0 { int handle; int result; int unk8; };
struct SO_1B1BF0 { char pad0[0x17C]; SLOT_1B1BF0 slots[6]; };
extern "C" {
int func_001B1B98(SO_1B1BF0 *, int);
void ResolveSlotSoAsegs(SO_1B1BF0 *self) {
    for (int index = 0; index < 6; index++) {
        SLOT_1B1BF0 *slot = &self->slots[index];
        if (slot->handle != -1) {
            slot->result = func_001B1B98(self, slot->handle);
            slot->handle = -1;
        }
    }
}
}
