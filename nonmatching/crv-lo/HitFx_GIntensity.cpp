#include "sly2.h"
struct HITFXDEF156898 { char pad[0x54]; float scale; char pad1[8]; float duration; };
struct HITFX156898 { char pad[0x14]; HITFXDEF156898 *def; char pad1[0x34]; float start; };
extern "C" {
extern float g_2dded0;
extern float g_2bdce0;
extern float g_2bdcf0[3];
float HitFx_GIntensity(HITFX156898 *fx)
{
    HITFXDEF156898 *def = fx->def;
    float duration = def->duration;
    if (0.0f < duration) {
        float limit = g_2bdce0;
        float divisor = limit < duration ? limit : duration;
        float t = (g_2dded0 - fx->start) / divisor;
        t = 1.0f < t ? 1.0f : t;
        return def->scale * (g_2bdcf0[0] + t * (g_2bdcf0[1] + t * g_2bdcf0[2]));
    }
    return def->scale;
}
}
