#include "sly2.h"
struct VIFS;
void EnsureVu1Code(VIFS *, void *, void *);
extern char RO_0025B880[];
extern char RO_0025C1B0[];
void func_0016EA20(VIFS *pvifs)
{
    EnsureVu1Code(pvifs, RO_0025B880, RO_0025C1B0);
}
