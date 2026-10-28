#include "sly2.h"
struct SL { char *first; char *last; int offset; };
struct SLI { int pad0; char **slot; int pad8; SLI *next; };
extern "C" SLI *g_2dd2f8;
void RemoveSlEntry(SL *list, void *entry)
{
    char **removed = (char **)((char *)entry + list->offset);
    char **toRemoved = (char **)list;
    if (entry != list->first) {
        char *current;
        do {
            current = *toRemoved;
            toRemoved = (char **)(current + list->offset);
        } while (entry != *toRemoved);
    }
    for (SLI *iterator = g_2dd2f8; iterator; iterator = iterator->next) {
        if (iterator->slot == removed)
            iterator->slot = toRemoved;
    }
    char *following = *removed;
    *toRemoved = following;
    if (list->first == 0)
        list->last = 0;
    else if (following == 0)
        list->last = (char *)toRemoved - list->offset;
    *removed = 0;
}
