/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct ENTRY { unsigned key; int pad4; int pad8; ENTRY *next; };
struct ALLOCVT { char pad[0x10]; short delta; short index; void *(*realloc)(void *, void *, int, int); };
struct ALLOC { ALLOCVT *vt; };
struct HASHTABLE { int count; ENTRY **buckets; int unk8; ALLOC *alloc; };
void HashTable_Resize(HASHTABLE *table, int newCount)
{
    ENTRY *cur; ENTRY *chain; int index; cur = chain = 0;
    for (index = 0; index < table->count; index++) {
        cur = table->buckets[index];
        if (cur) {
            while (cur->next) cur = cur->next;
            cur->next = chain;
            chain = table->buckets[index];
        }
    }
    table->count = newCount;
    ALLOC *alloc = table->alloc;
    void *fresh = alloc->vt->realloc((char *)alloc + alloc->vt->delta, table->buckets, newCount << 2, 3);
    table->buckets = (ENTRY **)fresh;
    memset(fresh, 0, table->count << 2);
    cur = chain;
    while (cur) {
        ENTRY *next = cur->next;
        unsigned slot = cur->key % table->count;
        cur->next = table->buckets[slot];
        table->buckets[slot] = cur;
        cur = next;
    }
}
