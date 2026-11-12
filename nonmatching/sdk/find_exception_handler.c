typedef struct ExceptionEntry {
    unsigned int first;
    unsigned int second;
    int value;
    unsigned int handlerArg;
} ExceptionEntry;

typedef struct ExceptionTable {
    int header00;
    int header04;
    ExceptionEntry entries[1];
} ExceptionTable;

typedef struct ExceptionHandler {
    int (*call)(struct ExceptionHandler *self, unsigned int arg, ExceptionTable *table);
} ExceptionHandler;

int find_exception_handler(unsigned int argument, ExceptionTable *table, ExceptionHandler *handler, int isEntry, int *pFound)
{
    int result;
    unsigned int key;
    int index;
    ExceptionEntry *entry;

    *pFound = 1;
    result = 0;
    if (table == 0)
        return result;
    index = 0;
    if (isEntry == 0) {
        key = argument - 1;
    } else {
        ExceptionEntry *cursor = (ExceptionEntry *)argument;
        index = ((int)cursor - (int)table->entries) >> 4;
        key = cursor->second - 1;
        if (table->entries[index].first != 0xFFFFFFFF)
            index++;
    }
    for (entry = &table->entries[index]; entry->first != 0xFFFFFFFF; entry++) {
        if (key < entry->first)
            continue;
        if (key >= entry->second)
            continue;
        if (entry->handlerArg == 0) {
            if (result == 0)
                result = entry->value;
            continue;
        }
        if (handler->call == 0)
            continue;
        if (handler->call(handler, entry->handlerArg, table) == 0)
            continue;
        if (result == 0)
            result = entry->value;
        *pFound = 0;
        return result;
    }
    return result;
}
