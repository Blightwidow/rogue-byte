#include "sly2.h"
struct ANIMREF { int kind; void *pdata; };
extern "C" void *func_0020C010(int);
extern "C" void *func_0020CA00(int);
void CopyAb(void *, void *, unsigned int);

void CloneAnimref(ANIMREF *p)
{
    void *n;
    switch (p->kind) {
    case 2: n = func_0020C010(0x40); CopyAb(n, p->pdata, 0x40); p->pdata = n; break;
    case 3: n = func_0020CA00(0xD0); CopyAb(n, p->pdata, 0xD0); p->pdata = n; break;
    }
}
