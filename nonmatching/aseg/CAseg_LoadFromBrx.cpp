#include "alloc.h"
struct VT { char pad0[8]; short delta; short unused; void (*fn)(void *, void *); };
struct OBJ { VT *vt; };
struct ENTRY {
    unsigned id : 20;
    unsigned value : 10;
    unsigned flag : 1;
    unsigned kind : 1;
    OBJ *object;
};
struct RECORD { int field0; int field4; OBJ *object; };
struct EVENTS { int count; void *array; };
struct ASEG {
    char pad0[0x5C];
    int entryCount;
    ENTRY *entries;
    int recordCount;
    RECORD *records;
    char pad6c[8];
    float duration;
    char pad78[0x20];
    EVENTS eventsA;
    EVENTS eventsB;
    EVENTS eventsC;
};
extern "C" {
float F32Read__18CBinaryInputStream(void *);
int S16Read__18CBinaryInputStream(void *);
int S32Read__18CBinaryInputStream(void *);
int S8Read__18CBinaryInputStream(void *);
int U8Read__18CBinaryInputStream(void *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
OBJ *PacrNew(int);
OBJ *PacpNew__F4ACVK(int);
void LoadAsegEventsFromBrx(void *, void *, int, int *, void *);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, void *);
void CAseg_LoadFromBrx(ASEG *aseg, void *bis) {
    ALLOCREQ request;
    int index = 0;
    aseg->duration = F32Read__18CBinaryInputStream(bis);
    aseg->entryCount = S16Read__18CBinaryInputStream(bis);
    request.cb = aseg->entryCount * 8;
    request.cbAlign = 0x10;
    aseg->entries = (ENTRY *)PvAllocSwImpl__Fi(&request);
    if (aseg->entryCount > 0) {
        do {
            ENTRY *entry = &aseg->entries[index];
            entry->id = S32Read__18CBinaryInputStream(bis);
            entry->value = S16Read__18CBinaryInputStream(bis);
            int id = S8Read__18CBinaryInputStream(bis);
            if (id != -1) {
                OBJ *object = PacrNew(id);
                entry->object = object;
                object->vt->fn((char *)object + object->vt->delta, bis);
                entry->kind = 0;
            }
            id = S8Read__18CBinaryInputStream(bis);
            if (id != -1) {
                OBJ *object = PacpNew__F4ACVK(id);
                entry->object = object;
                object->vt->fn((char *)object + object->vt->delta, bis);
                entry->kind = 1;
            }
            index++;
            entry->flag = U8Read__18CBinaryInputStream(bis) != 0;
        } while (index < aseg->entryCount);
    }
    index = 0;
    int count = U8Read__18CBinaryInputStream(bis);
    int *countA = &aseg->eventsA.count;
    void **arrayA = &aseg->eventsA.array;
    int *countB = &aseg->eventsB.count;
    void **arrayB = &aseg->eventsB.array;
    int *countC = &aseg->eventsC.count;
    void **arrayC = &aseg->eventsC.array;
    aseg->recordCount = count;
    request.cb = count * 0xC;
    request.cbAlign = 0x10;
    aseg->records = (RECORD *)PvAllocSwClearImpl__Fi(&request);
    if (aseg->recordCount > 0) {
        do {
            index++;
            RECORD *record = &aseg->records[index - 1];
            record->field0 = U8Read__18CBinaryInputStream(bis);
            record->field4 = S32Read__18CBinaryInputStream(bis);
            OBJ *object = PacpNew__F4ACVK(S8Read__18CBinaryInputStream(bis));
            record->object = object;
            object->vt->fn((char *)object + object->vt->delta, bis);
        } while (index < aseg->recordCount);
    }
    LoadAsegEventsFromBrx(aseg, bis, 0, countA, arrayA);
    LoadAsegEventsFromBrx(aseg, bis, 1, countB, arrayB);
    LoadAsegEventsFromBrx(aseg, bis, 0, countC, arrayC);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(aseg, bis);
}
}
