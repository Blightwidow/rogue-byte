#include "sly2.h"
struct ENTRY { char pad[4]; int state; char pad2[4]; float t; };
struct GUARD { char pad[0x2C0]; unsigned long grf; char pad2[0x3D0 - 0x2C8]; int blocked; char pad3[0xF64 - 0x3D4]; void *psensor; };
extern "C" {
int FIsBasicDerivedFrom(void *, int);
unsigned long GrfsgsFromSgs(int);
ENTRY *PentryFindSensorLo(void *, void *);
extern float g_2dded0;
extern float D_FLT_002C3DAC;
}
extern "C" int func_0020A298(GUARD *pguard, void *plo, unsigned long grfsgs)
{
    unsigned int result;
    if (pguard->blocked == 0) {
        if (FIsBasicDerivedFrom(plo, 0x36)) {
            if (!FIsBasicDerivedFrom(pguard, 0x3A)) {
                if ((pguard->grf & GrfsgsFromSgs(6)) == 0)
                    return 1;
            }
        }
        ENTRY * pentry;
        pentry = PentryFindSensorLo(pguard->psensor, plo);
        if (pentry != 0 && pentry->state != 0 && (g_2dded0 - pentry->t < D_FLT_002C3DAC) == 0) {
            if ((pguard->grf & grfsgs) == 0)
                { result = 0; goto done; }
        }
        return 1;
    }
    { result = 0; goto done; }
done:
    return result;
}
