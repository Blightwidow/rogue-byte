extern "C" {
struct Emitter_1C4848 { char pad[8]; void *alloc; };
struct StackParams_1C4848 { int size; int align; };
struct Owner_1C4848 { char pad[0x4778]; unsigned count; int slots[4]; };
Emitter_1C4848 *PemitbEnsureEmitter(int, int);
void *PvAllocSwClearImpl__Fi(StackParams_1C4848 *);

void func_001C4848(Owner_1C4848 *owner, int id) {
    unsigned count = owner->count;
    if (count < 4U) {
        owner->slots[count] = id;
        owner->count = count + 1;
        Emitter_1C4848 *emitter = PemitbEnsureEmitter(id, 1);
        if (emitter->alloc == 0) {
            StackParams_1C4848 params;
            params.size = 0x14;
            params.align = 0x10;
            emitter->alloc = PvAllocSwClearImpl__Fi(&params);
        }
    }
}
}
