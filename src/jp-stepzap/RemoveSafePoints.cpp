#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct SP { int a; int b; int c; int d; QW q1; };
struct SPL { int pad0; int count; int pad1[2]; SP items[1]; };
void RemoveSafePoints(SPL *list, int a, int b)
{
    SP *dst = list->items;
    SP *end = list->items + list->count;
    SP *src = dst;
    while (src < end) {
        if ((a == 0 || a != src->a) && (b == 0 || b != src->c)) {
            if (src != dst) {
                QW *d = (QW*)dst; QW *s = (QW*)src;
                d[0] = s[0]; d[1] = s[1];
            }
            dst++;
        }
        src++;
    }
    list->count = dst - list->items;
}
