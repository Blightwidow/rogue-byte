// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" void *memmove(void *, const void *, unsigned int);
struct CLOCK_2085D0 { float t; float dt; };
extern "C" CLOCK_2085D0 g_2dded0;

struct SensedEntry {
    void *plo;
    int seen;
    float time;
    int field0C;
};

struct SensedList {
    char pad[0xFC];
    unsigned int count;
    SensedEntry entries[8];
};

struct Guard {
    char pad0[0x3A4];
    int tail;
    char pad1[0xF64 - 0x3A8];
    SensedList *psensed;
};

extern "C" SensedEntry *PentryFindSensorLo(SensedList *list, void *plo);

// Retail keeps the found entry, the count, the insertion index and the entry address in one
// callee-saved register ($s0): every step (subtract the tail, scale by 16, add the 0x100 array
// offset, add the list) writes it in place, so the source reuses one word-sized slot variable.
// The last step goes through an inline helper: written in place (`slot = list + slot`) GCC swaps
// the operands (`addu s0, s0, a0`); retail has the list first. The time is read from the clock
// struct (Clock_135248 elsewhere): as a plain float its load is hoisted above the stores.
static inline unsigned int OffsetInList(SensedList *list, unsigned int offset)
{
    return (unsigned int)list + offset;
}

extern "C" int AddGuardSensedObject(Guard *guard, void *plo, int append)
{
    if (plo != 0) {
        if (plo == guard)
            return 0;
        unsigned int slot = 0;
        if (append == 0)
            slot = (unsigned int)PentryFindSensorLo(guard->psensed, plo);
        if (slot != 0)
            return 0;
        SensedList *list = guard->psensed;
        slot = list->count;
        if (slot >= 8) {
            if (append != 0)
                return 0;
            int tail = guard->tail;
            if (tail > 0) {
                guard->tail = tail - 1;
                slot = 8;
                slot -= tail;
                slot *= sizeof(SensedEntry);
                slot += 0x100;
                slot = OffsetInList(list, slot);
                memmove((SensedEntry *)slot + 1, (SensedEntry *)slot, (tail - 1) * sizeof(SensedEntry));
            } else {
                return 0;
            }
        } else if (append != 0) {
            slot = (unsigned int)&list->entries[slot];
        } else {
            int tail = guard->tail;
            slot -= tail;
            slot *= sizeof(SensedEntry);
            slot += 0x100;
            slot = OffsetInList(list, slot);
            memmove((SensedEntry *)slot + 1, (SensedEntry *)slot, tail * sizeof(SensedEntry));
        }
        SensedEntry *entry = (SensedEntry *)slot;
        entry->plo = plo;
        entry->seen = 0;
        entry->time = g_2dded0.t;
        guard->psensed->count++;
        return 1;
    }
    return 0;
}
