#include "sly2.h"
struct STEPGUARD;
void *memmove(void *, const void *, unsigned int);
#define COUNT(g) (*(int *)((char *)(g) + 0x3A8))
#define LIST(g) ((int *)((char *)(g) + 0x3A8 + 4))
void RemoveGuardIgnoredClass(STEPGUARD *guard, int cid)
{
    int index;
    for (index = 0; index < COUNT(guard); index++) {
        int *list = LIST(guard);
        if (list[index] == cid) {
            memmove(&list[index], &list[index + 1], (COUNT(guard) - index) * 4 - 4);
            COUNT(guard) -= 1;
        }
    }
}
