extern "C" {
void HashTable_Clear(char *);
void HashTable_Clear_thunk(char *table) {
    HashTable_Clear(table + 0x14);
}
}
