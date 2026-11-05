#include "sly2.h"
struct Region { char pad[0x110]; int inside; };
struct Cm { char pad[0x90]; QW pos; };
extern "C" {
extern char B_003DD490;
int CploFindSwObjectsByClass(char *, unsigned, int, void *, int, Region **);
void func_002273F0(Region *, QW);
void qsort(void *, int, int, int (*)(const void *, const void *));
int func_0014E000(const void *, const void *);
void bevy_camera_cm_14e148(Cm *, Region *);
void func_0014E078(Cm *pcm)
{
    Region *aplo[0x20];
    QW posCm = pcm->pos;
    int cplo = CploFindSwObjectsByClass(&B_003DD490, 0x105, 5, 0, 0x20, aplo);
    for (int iplo = 0; iplo < cplo; iplo++)
        func_002273F0(aplo[iplo], posCm);
    qsort(aplo, cplo, 4, func_0014E000);
    if (cplo > 0 && aplo[0]->inside == 1)
        bevy_camera_cm_14e148(pcm, aplo[0]);
}
}
