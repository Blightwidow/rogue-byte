#include "sly2.h"
struct LM;
struct AMB { char p0[0x70]; float vol[6]; char p1[0x3BC - 0x88]; unsigned dirty; };
extern LM g_2bbb60;
float GLimitLm(LM *, float);
extern "C" void SetAmbGrf(AMB *, int, int);
extern "C" void SetAmbSlotVolume(AMB *amb, unsigned slot, float vol)
{
    if (slot < 6) {
        float limited = GLimitLm(&g_2bbb60, vol);
        float *vols = amb->vol;
        float *slotvol = &vols[slot];
        int oldvalue = (int)(*slotvol * 1024.0f);
        int newvalue = (int)(limited * 1024.0f);
        if (newvalue != oldvalue) {
            amb->dirty |= 1 << slot;
            *slotvol = limited;
            SetAmbGrf(amb, 0x80, 0x80);
        }
    }
}
