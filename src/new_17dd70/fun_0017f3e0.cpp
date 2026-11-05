#include "sly2.h"
struct ENTRY { int value; int pad[3]; };
void func_0017F3E0(void *unused, int count, ENTRY *pentry)
{
    if (count > 0)
    {
        do
        {
            pentry->value = -1;
            pentry++;
        } while (--count != 0);
    }
}
