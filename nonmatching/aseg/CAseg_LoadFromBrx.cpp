struct ALLOCREQ_12F2A8 { int size; int align; };
struct VT_12F2A8 { char pad0[8]; short delta; short unused; void (*fn)(void *, void *); };
struct OBJ_12F2A8 { VT_12F2A8 *vt; };
struct ENTRY_12F2A8 {
    unsigned id : 20;
    unsigned value : 10;
    unsigned flag : 1;
    unsigned kind : 1;
    OBJ_12F2A8 *object;
};
struct RECORD_12F2A8 { int field0; int field4; OBJ_12F2A8 *object; };
struct ASEG_12F2A8 {
    char pad0[0x5C];
    int entryCount;
    ENTRY_12F2A8 *entries;
    int recordCount;
    RECORD_12F2A8 *records;
    char pad6c[8];
    float duration;
    char pad78[0x20];
    char eventsA[8];
    char eventsB[8];
    char eventsC[8];
};
extern "C" {
float F32Read__18CBinaryInputStream(void *);
int S16Read__18CBinaryInputStream(void *);
int S32Read__18CBinaryInputStream(void *);
int S8Read__18CBinaryInputStream(void *);
int U8Read__18CBinaryInputStream(void *);
void *PvAllocSwImpl__Fi(ALLOCREQ_12F2A8 *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ_12F2A8 *);
OBJ_12F2A8 *PacrNew(int);
OBJ_12F2A8 *PacpNew__F4ACVK(int);
void LoadAsegEventsFromBrx(void *, void *, int, void *);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, void *);
void CAseg_LoadFromBrx(ASEG_12F2A8 *aseg, void *bis) {
    ALLOCREQ_12F2A8 request;
    int index;
    int count;
    ENTRY_12F2A8 *entry;
    RECORD_12F2A8 *record;
    int id;
    OBJ_12F2A8 *object;
    VT_12F2A8 *vt;
    int delta;
    void (*fn)(void *, void *);
    void *eventsA;
    void *eventsC;
    aseg->duration = F32Read__18CBinaryInputStream(bis);
    aseg->entryCount = S16Read__18CBinaryInputStream(bis);
    request.size = aseg->entryCount * 8;
    request.align = 0x10;
    aseg->entries = (ENTRY_12F2A8 *)PvAllocSwImpl__Fi(&request);
    index = 0;
    if (aseg->entryCount > 0) {
        do {
            entry = &aseg->entries[index];
            entry->id = S32Read__18CBinaryInputStream(bis);
            entry->value = S16Read__18CBinaryInputStream(bis);
            id = S8Read__18CBinaryInputStream(bis);
            if (id != -1) {
                object = PacrNew(id);
                entry->object = object;
                vt = object->vt;
                delta = vt->delta;
                fn = vt->fn;
                fn((char *)object + delta, bis);
                entry->kind = 0;
            }
            id = S8Read__18CBinaryInputStream(bis);
            if (id != -1) {
                object = PacpNew__F4ACVK(id);
                entry->object = object;
                vt = object->vt;
                delta = vt->delta;
                fn = vt->fn;
                fn((char *)object + delta, bis);
                entry->kind = 1;
            }
            index++;
            entry->flag = U8Read__18CBinaryInputStream(bis) != 0;
        } while (index < aseg->entryCount);
    }
    index = 0;
    count = U8Read__18CBinaryInputStream(bis);
    eventsA = aseg->eventsA;
    aseg->recordCount = count;
    request.size = count * 0xC;
    eventsC = aseg->eventsC;
    request.align = 0x10;
    aseg->records = (RECORD_12F2A8 *)PvAllocSwClearImpl__Fi(&request);
    if (aseg->recordCount > 0) {
        do {
            index++;
            record = &aseg->records[index - 1];
            record->field0 = U8Read__18CBinaryInputStream(bis);
            record->field4 = S32Read__18CBinaryInputStream(bis);
            object = PacpNew__F4ACVK(S8Read__18CBinaryInputStream(bis));
            record->object = object;
            vt = object->vt;
            delta = vt->delta;
            fn = vt->fn;
            fn((char *)object + delta, bis);
        } while (index < aseg->recordCount);
    }
    LoadAsegEventsFromBrx(aseg, bis, 0, eventsA);
    LoadAsegEventsFromBrx(aseg, bis, 1, aseg->eventsB);
    LoadAsegEventsFromBrx(aseg, bis, 0, eventsC);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(aseg, bis);
}
}
