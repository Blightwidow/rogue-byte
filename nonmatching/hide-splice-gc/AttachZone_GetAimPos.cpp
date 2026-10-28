#include "sly2.h"
struct Alo { char pad[0x110]; QW point; char pad2[0x3C]; void *target; };
extern "C" QW PosLoWorld(void *);
extern "C" QW ConvertAloPos(Alo *, int, QW);
extern int g_2dfb84;
extern float g_2be908;

static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float ZOf(QW q) { register QW zeroReg asm("$0"); return Lane(__builtin_pextuw(zeroReg, q)); }

extern "C" void AttachZone_GetAimPos(Alo *zone, void *joint, QW *aim)
{
    if (aim != 0) {
        if (g_2dfb84 != 0) {
            *aim = PosLoWorld(zone->target);
            ((float *)aim)[2] = ((float *)aim)[2] + g_2be908;
        } else {
            *aim = ConvertAloPos(zone, 0, zone->point);
            ((float *)aim)[2] = ZOf(PosLoWorld(zone->target)) + g_2be908;
        }
    }
}
