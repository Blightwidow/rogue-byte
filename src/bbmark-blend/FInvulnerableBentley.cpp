#include "bentley.h"
extern "C" int func_00194640(void *, int);
extern "C" int FInvulnerableJt(void *, int);
extern "C" int FInvulnerableBentley(BENTLEY *pbentley, int grfjt)
{
    int result;
    if (pbentley->state != 3) {
        if (pbentley->state == 0xD && grfjt == 0x4000)
            return 1;
    } else {
        result = 1;
        if (func_00194640((char *)pbentley + 0x4C0, grfjt) != 0)
            return result;
    }
    return FInvulnerableJt(pbentley, grfjt);
}