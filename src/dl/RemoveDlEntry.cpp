#include "sly2.h"
struct DLE { char *next; char *prev; };
struct DL { char *first; char *last; int offset; };
struct DLI { int pad0; DLE *current; int pad8; DLI *next; };
extern DLI *g_2dd2fc;

void RemoveDlEntry(DL *list, char *object)
{
    DLE *entry = (DLE *)(object + list->offset);
    DLI *iterator;
    for (iterator = g_2dd2fc; iterator != 0; iterator = iterator->next) {
        if (iterator->current == entry) {
            if (entry->prev != 0)
                iterator->current = (DLE *)(entry->prev + list->offset);
            else
                iterator->current = (DLE *)list;
        }
    }
    if (entry->prev != 0)
        ((DLE *)(entry->prev + list->offset))->next = entry->next;
    else
        list->first = entry->next;
    if (entry->next != 0)
        ((DLE *)(entry->next + list->offset))->prev = entry->prev;
    else
        list->last = entry->prev;
    entry->next = 0;
    entry->prev = 0;
}
