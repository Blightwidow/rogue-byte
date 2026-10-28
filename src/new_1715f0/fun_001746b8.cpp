extern "C" void RemoveLoHierarchy(void*);
extern "C" void func_00173928(void*, void*, int, int);
struct Slot { int owner; char pad[0x2C]; };
struct Spawner { char pad0[0x5C]; int count; Slot* slots; };
extern "C" void func_001746B8(Spawner* self)
{
    RemoveLoHierarchy(self);
    if (self->slots) {
        for (int i = 0; i < self->count; i++) {
            Slot* slot = &self->slots[i];
            if (slot->owner) func_00173928(self, slot, 0, 0);
        }
    }
}
