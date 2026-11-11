#include "vu0inline.h"
#include "types.h"
#include "ps2inline.h"
struct ATTACHZONE { char pad[0x110]; QW field_0x110; char pad2[0x3C]; void *field_0x15C; };
extern "C" {
QW ConvertAloPos(ATTACHZONE *, void *, QW);
QW PosLoWorld(void *);
extern float g_2be908;
extern int g_2dfb84;
}
void AttachZone_GetAimPos(ATTACHZONE *pzone, int unused, QW *ppos)
{
    if (ppos) {
        float *pcomponents = (float *)ppos;
        if (g_2dfb84 != 0) {
            *ppos = PosLoWorld(pzone->field_0x15C);
            pcomponents[2] = pcomponents[2] + g_2be908;
        } else {
            *ppos = ConvertAloPos(pzone, 0, pzone->field_0x110);
            pcomponents[2] = LaneZInGeneralRegister(PosLoWorld(pzone->field_0x15C)) + g_2be908;
        }
    }
}
