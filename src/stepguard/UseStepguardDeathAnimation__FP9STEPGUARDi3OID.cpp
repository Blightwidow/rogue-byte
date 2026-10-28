#include "sly2.h"
enum OID { OID_NONE = -1 };
struct STEPGUARD { char pad[0x230]; unsigned count; };
void UseStepguardDeathAnimation(STEPGUARD *pguard, int a, OID oid);
void UseStepguardDeathAnimation(STEPGUARD *pguard, int a, OID oid)
{
    unsigned n = pguard->count;
    if (n < 4) {
        pguard->count = n + 1;
        int *pitem = (int *)((char *)pguard + (n * 0x18 + 0x234));
        pitem[0] = a;
        pitem[1] = oid;
    }
}
