struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0xC]; VT *vt; };
struct ENTRY { void *key; char pad[0xC]; Obj *old; char pad2[0x1C]; };
struct STATE { char pad[0x4678]; int count; char pad1[4]; ENTRY entries[1]; char pad2[0x4744 - 0x4680 - 0x30]; void *owner; };
extern "C" void *PloSpawnTargetIndicator(STATE *, void *, ENTRY *);

extern "C" void func_00195608(STATE *state, void *key)
{
    ENTRY *entry;
    if (key != 0) {
        if (state->owner != 0) {
            for (int index = 0; index < state->count; index++) {
                ENTRY *candidate = &state->entries[index];
                if (key == candidate->key) { entry = candidate; break; }
            }
            if (entry != 0) {
                void *result = PloSpawnTargetIndicator(state, state->owner, entry);
                if (result != 0) {
                    Obj *old = entry->old;
                    if (old != 0) {
                        VT *vt = old->vt;
                        vt->fn((char *)old + vt->delta);
                    }
                    entry->old = (Obj *)result;
                }
            }
        }
    }
}
