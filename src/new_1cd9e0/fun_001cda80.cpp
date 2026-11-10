#include "sly2.h"
#include "sw.h"
extern "C" void func_001A3EE8(SW *);
extern "C" void func_001CD9E0(SW *);
extern "C" void GadgetMenu_DrawSlotLabels(void *);
extern "C" void func_001574A0(void *);
extern char B_003B3980[];
extern char *B_003D4A50;
extern char B_003DA0F0[];
extern char B_002DEA00[];
extern char g_2dea28[];

void func_001CDA80(SW *sw)
{
    int index;
    func_001A3EE8(sw);
    sw->field_0x3D60 = sw->field_0x3D60 + 1;
    B_003D4A50 = B_003B3980;
    if (sw->frame != sw->frameLast) {
        sw->frameLast = sw->frame;
        func_001CD9E0(sw);
    }
    index = 0;
    sw->pigrfentryRunning = &index;
    for (index = 0; index < sw->cgrfentry; index++) {
        GRFENTRY *pgrfentry = &sw->agrfentry[index];
        if ((pgrfentry->grf & 0x88) == 8)
            pgrfentry->plo->Slot19();
    }
    sw->pigrfentryRunning = 0;
    GadgetMenu_DrawSlotLabels(B_003DA0F0);
    func_001574A0(B_002DEA00);
    func_001574A0(g_2dea28);
}
