#include "sly2.h"
struct VIFS { int pad[3]; int *pcur; void AddVifStcycl(int, int); };
void VIFS::AddVifStcycl(int wl, int cl)
{
    int *pword = pcur;
    pcur = pword + 1;
    *pword = cl | (wl << 8) | 0x1000000;
}
