#include "sly2.h"
struct SO { char pad[0x40]; unsigned *grf; char pad1[0xCC - 0x44]; int stamp; };
struct SW { char pad[0x3D5C]; int frame; };
extern "C" {
int CploFindSwObjectsByClass(SW *, int, int, void *, int, SO **);
void func_001681F8(void *);
}
extern "C" void func_001CD9E0(SW *sw)
{
    SO *apso[0x400];
    int count = CploFindSwObjectsByClass(sw, 0x105, 0x30, 0, 0x400, apso);
    for (int index = 0; index < count; index++) {
        SO *so = apso[index];
        unsigned bits = (unsigned)so->grf;
        if (!(bits & 1))
            bits = *so->grf;
        if ((bits & 8) && so->stamp != sw->frame)
            func_001681F8((char *)so + 0x80);
    }
}
