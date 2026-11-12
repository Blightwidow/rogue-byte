#include "alloc.h"
#include "bis.h"
struct ACOBJ { virtual void LoadFromBrx(CBinaryInputStream *pbis); };
struct ENTRY {
    unsigned id : 20;
    unsigned value : 10;
    unsigned flag : 1;
    unsigned kind : 1;
    ACOBJ *object;
};
struct RECORD { int field0; int field4; ACOBJ *object; };
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
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
ACOBJ *PacrNew(int);
ACOBJ *PacpNew__F4ACVK(int);
void LoadAsegEventsFromBrx(void *, CBinaryInputStream *, int, int *, void *);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, CBinaryInputStream *);
void CAseg_LoadFromBrx(ASEG *aseg, CBinaryInputStream *pbis) {
    ALLOCREQ request;
    int index = 0;
    aseg->duration = pbis->F32Read();
    aseg->entryCount = pbis->S16Read();
    request.cb = aseg->entryCount * 8;
    request.cbAlign = 0x10;
    aseg->entries = (ENTRY *)PvAllocSwImpl__Fi(&request);
    if (aseg->entryCount > 0) {
        do {
            ENTRY *entry = &aseg->entries[index];
            entry->id = pbis->S32Read();
            entry->value = pbis->S16Read();
            int id = pbis->S8Read();
            if (id != -1) {
                ACOBJ *object = PacrNew(id);
                entry->object = object;
                object->LoadFromBrx(pbis);
                entry->kind = 0;
            }
            id = pbis->S8Read();
            if (id != -1) {
                ACOBJ *object = PacpNew__F4ACVK(id);
                entry->object = object;
                object->LoadFromBrx(pbis);
                entry->kind = 1;
            }
            index++;
            entry->flag = pbis->U8Read() != 0;
        } while (index < aseg->entryCount);
    }
    int indexRecord = 0;
    int count = pbis->U8Read();
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
            RECORD *record = &aseg->records[indexRecord];
            record->field0 = pbis->U8Read();
            record->field4 = pbis->S32Read();
            ACOBJ *object = PacpNew__F4ACVK(pbis->S8Read());
            record->object = object;
            object->LoadFromBrx(pbis);
            indexRecord++;
        } while (indexRecord < aseg->recordCount);
    }
    LoadAsegEventsFromBrx(aseg, pbis, 0, countA, arrayA);
    LoadAsegEventsFromBrx(aseg, pbis, 1, countB, arrayB);
    LoadAsegEventsFromBrx(aseg, pbis, 0, countC, arrayC);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(aseg, pbis);
}
}
