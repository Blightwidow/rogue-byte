#include "sly2.h"
struct VT { char pad[8]; short delta; short index; void *(*fn)(void *, int, int); };
struct Obj { VT *vt; };
struct HashEntry { int hash; int key; int value; int next; };
struct HashTable { unsigned buckets; HashEntry **table; int count; Obj *alloc; };
extern "C" {
void HashTable_Resize(HashTable *, int);
int HashSz(int);
int *HashTable_Insert(HashTable *table, int *key, int *value)
{
    table->count++;
    if (!table->buckets) HashTable_Resize(table, 0x35);
    unsigned hash = HashSz(*key);
    unsigned bucket = hash % table->buckets;
    Obj *alloc = table->alloc;
    HashEntry *entry = (HashEntry *)alloc->vt->fn((char *)alloc + alloc->vt->delta, 0x10, 3);
    memset(entry, 0, 0x10);
    entry->hash = hash;
    entry->key = *key;
    entry->value = *value;
    entry->next = (int)table->table[bucket];
    table->table[bucket] = entry;
    return &entry->value;
}
}
