#include "sly2.h"
extern const char D_002C40C8[];
void CopyAb(void *, void *, unsigned int);

int CchAchFromUl(char *buffer, int size, unsigned long value, unsigned int radix)
{
    char *end = buffer + size;
    char *cursor = end;
    do {
        cursor--;
        *cursor = D_002C40C8[value % radix];
        value = value / radix;
        if (value == 0) break;
    } while (buffer <= cursor);
    int count = end - cursor;
    if (count != 0 && buffer < cursor)
        CopyAb(buffer, cursor, count);
    return count;
}
